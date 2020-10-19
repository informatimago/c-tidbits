all:findsubstring
	(echo caberqiitefg ; echo 5) | OUTPUT_PATH=output-1.txt ./findsubstring && cat output-1.txt
	(echo aeiouia      ; echo 3) | OUTPUT_PATH=output-2.txt ./findsubstring && cat output-2.txt

clean:
	-rm -rf findsubstring *.dSYM out.txt
