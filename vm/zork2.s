.name "zork2"
.comment "I'm ALIIIIVE"

		ld   %0,r3
l2:		sti r1, %:hello, %1
		and r1, %0, r1

hello:	
	zjmp %:hello
		zjmp %0	

live: live %1
      zjmp %:hello

what: live %1
      zjmp %:hello
