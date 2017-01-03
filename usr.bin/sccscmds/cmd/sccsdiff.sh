: sccsdiff 2.2
: DESCRIPTION:
:	Run bdiff on two versions of a set of SCCS files.  ${1}  and  ${2}
:	are two "(" old/new ")" SCCS get specifiers "(" -r... or -c...")".
:
:	If ${3} begins with a "-" it is taken to be an  argument  for  pr
:	"(" e.g. -l84 ")", ${3} ${4} ... are SCCS files which are gotten.
:
trap "rm -f /tmp/get$$  > /dev/null; exit 1" 0 1 2 3 13 14 15
if [ ${#} -lt 3 ]
then
	echo "Usage: sccsdiff -r<old> -r<new> [pr flags] sccsfile ..."
	exit 1
fi
a="${1}"
shift
b="${1}"
shift
c="`expr substr "${1}" 1 1`"
if [ "x${c}" = x- ]
then
	c="${1}"
	shift
else
	c=" "
fi
while [ ${1} ]
do
	get -s -p -k ${a} ${1}  > /tmp/get$$
	if [ ${?} -eq 0 ]
	then
	get -s -p -k ${b} ${1} ^ bdiff /tmp/get$$ - ^ pr ${c} -h "${1}: ${a} vs. ${b}"
	fi
	shift
done
rm /tmp/get$$
