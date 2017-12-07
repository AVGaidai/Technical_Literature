  .model  tiny
	.code
	ORG      100h

start: 
  MOV  AH,2
	MOV  DL,41h
	INT  21h
	INT  20h
	END	 start
