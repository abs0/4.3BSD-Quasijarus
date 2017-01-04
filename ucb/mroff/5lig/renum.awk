BEGIN {
	new = 5
	print "/^\/Subrs/mark a"
}
($1 == "dup") && ($2 ~ /^[0-9]+$/ ) {
	printf "'a,$g/^.*$/s/^dup %s\>/dup %s/\n", $2, new
	printf "'a,$g/^.*$/s/\<%s callsubr\>/%s callsubr/\n", $2, new
	printf "'a,$g/^.*$/s/\<%s 4 callsubr\>/%s 4 callsubr/\n", $2, new
	new++
}
