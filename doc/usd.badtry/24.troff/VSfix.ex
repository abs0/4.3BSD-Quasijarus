" ex script for fixing VarianSpecial.ps
"	@(#)VSfix.ex	6.1 (Berkeley) 04/10/26
/^\/Encoding/c
/Encoding [
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %00
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %08
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %10
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %18
/c20/c21/c22/c23/c24/c25/c26/c27/c28/c29/c2A/c2B/c2C/c2D/c2E/c2F
/c30/c31/c32/c33/c34/c35/c36/c37/c38/c39/c3A/c3B/c3C/c3D/c3E/c3F
/c40/c41/c42/c43/c44/c45/c46/c47/c48/c49/c4A/c4B/c4C/c4D/c4E/c4F
/c50/c51/c52/c53/c54/c55/c56/c57/c58/c59/c5A/c5B/c5C/c5D/c5E/c5F
/c60/c61/c62/c63/c64/c65/c66/c67/c68/c69/c6A/c6B/c6C/c6D/c6E/c6F
/c70/c71/c72/c73/c74/c75/c76/c77/c78/c79/c7A/c7B/c7C/c7D/c7E/c7F
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %80
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %88
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %90
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %98
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %A0
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %A8
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %B0
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %B8
/c00/c01/c02/c03/c04/c05/c06/c07/c08/c09/c0A/c0B/c0C/c0D/c0E/c0F
/c10/c11/c12/c13/c14/c15/c16/c17/c18/c19/c1A/c1B/c1C/c1D/c1E/c1F
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %E0
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %E8
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %F0
/.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef %F8
] readonly def
.
/^%%DocumentNeededResources:/d
wq
