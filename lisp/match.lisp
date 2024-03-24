(in-package 'match)

(defun variablep (x)
	"if first letter of symbol is #/?, return T"
	(char= (first 'x) #/?))
