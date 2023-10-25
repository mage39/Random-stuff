
play:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)  
 319:	6c                   	ins    BYTE PTR es:[rdi],dx
 31a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
 321:	2d 6c 69 6e 75       	sub    eax,0x756e696c
 326:	78 2d                	js     355 <__abi_tag-0x37>
 328:	78 38                	js     362 <__abi_tag-0x2a>
 32a:	36 2d 36 34 2e 73    	ss sub eax,0x732e3436
 330:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 331:	2e 32 00             	cs xor al,BYTE PTR [rax]

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    al,0x0
 33a:	00 00                	add    BYTE PTR [rax],al
 33c:	20 00                	and    BYTE PTR [rax],al
 33e:	00 00                	add    BYTE PTR [rax],al
 340:	05 00 00 00 47       	add    eax,0x47000000
 345:	4e 55                	rex.WRX push rbp
 347:	00 02                	add    BYTE PTR [rdx],al
 349:	00 00                	add    BYTE PTR [rax],al
 34b:	c0 04 00 00          	rol    BYTE PTR [rax+rax*1],0x0
 34f:	00 03                	add    BYTE PTR [rbx],al
 351:	00 00                	add    BYTE PTR [rax],al
 353:	00 00                	add    BYTE PTR [rax],al
 355:	00 00                	add    BYTE PTR [rax],al
 357:	00 02                	add    BYTE PTR [rdx],al
 359:	80 00 c0             	add    BYTE PTR [rax],0xc0
 35c:	04 00                	add    al,0x0
 35e:	00 00                	add    BYTE PTR [rax],al
 360:	01 00                	add    DWORD PTR [rax],eax
 362:	00 00                	add    BYTE PTR [rax],al
 364:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .note.gnu.build-id:

0000000000000368 <.note.gnu.build-id>:
 368:	04 00                	add    al,0x0
 36a:	00 00                	add    BYTE PTR [rax],al
 36c:	14 00                	adc    al,0x0
 36e:	00 00                	add    BYTE PTR [rax],al
 370:	03 00                	add    eax,DWORD PTR [rax]
 372:	00 00                	add    BYTE PTR [rax],al
 374:	47                   	rex.RXB
 375:	4e 55                	rex.WRX push rbp
 377:	00 a7 88 ad 96 e0    	add    BYTE PTR [rdi-0x1f695278],ah
 37d:	c3                   	ret    
 37e:	e4 ad                	in     al,0xad
 380:	f8                   	clc    
 381:	dd 39                	fnstsw WORD PTR [rcx]
 383:	38 08                	cmp    BYTE PTR [rax],cl
 385:	33 49 06             	xor    ecx,DWORD PTR [rcx+0x6]
 388:	f4                   	hlt    
 389:	bc                   	.byte 0xbc
 38a:	63                   	.byte 0x63
 38b:	14                   	.byte 0x14

Disassembly of section .note.ABI-tag:

000000000000038c <__abi_tag>:
 38c:	04 00                	add    al,0x0
 38e:	00 00                	add    BYTE PTR [rax],al
 390:	10 00                	adc    BYTE PTR [rax],al
 392:	00 00                	add    BYTE PTR [rax],al
 394:	01 00                	add    DWORD PTR [rax],eax
 396:	00 00                	add    BYTE PTR [rax],al
 398:	47                   	rex.RXB
 399:	4e 55                	rex.WRX push rbp
 39b:	00 00                	add    BYTE PTR [rax],al
 39d:	00 00                	add    BYTE PTR [rax],al
 39f:	00 03                	add    BYTE PTR [rbx],al
 3a1:	00 00                	add    BYTE PTR [rax],al
 3a3:	00 02                	add    BYTE PTR [rdx],al
 3a5:	00 00                	add    BYTE PTR [rax],al
 3a7:	00 00                	add    BYTE PTR [rax],al
 3a9:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .gnu.hash:

00000000000003b0 <.gnu.hash>:
 3b0:	02 00                	add    al,BYTE PTR [rax]
 3b2:	00 00                	add    BYTE PTR [rax],al
 3b4:	06                   	(bad)  
 3b5:	00 00                	add    BYTE PTR [rax],al
 3b7:	00 01                	add    BYTE PTR [rcx],al
 3b9:	00 00                	add    BYTE PTR [rax],al
 3bb:	00 06                	add    BYTE PTR [rsi],al
 3bd:	00 00                	add    BYTE PTR [rax],al
 3bf:	00 00                	add    BYTE PTR [rax],al
 3c1:	00 81 00 00 00 00    	add    BYTE PTR [rcx+0x0],al
 3c7:	00 06                	add    BYTE PTR [rsi],al
 3c9:	00 00                	add    BYTE PTR [rax],al
 3cb:	00 00                	add    BYTE PTR [rax],al
 3cd:	00 00                	add    BYTE PTR [rax],al
 3cf:	00 d1                	add    cl,dl
 3d1:	65 ce                	gs (bad) 
 3d3:	6d                   	ins    DWORD PTR es:[rdi],dx

Disassembly of section .dynsym:

00000000000003d8 <.dynsym>:
	...
 3f0:	10 00                	adc    BYTE PTR [rax],al
 3f2:	00 00                	add    BYTE PTR [rax],al
 3f4:	12 00                	adc    al,BYTE PTR [rax]
	...
 406:	00 00                	add    BYTE PTR [rax],al
 408:	48 00 00             	rex.W add BYTE PTR [rax],al
 40b:	00 20                	add    BYTE PTR [rax],ah
	...
 41d:	00 00                	add    BYTE PTR [rax],al
 41f:	00 22                	add    BYTE PTR [rdx],ah
 421:	00 00                	add    BYTE PTR [rax],al
 423:	00 12                	add    BYTE PTR [rdx],dl
	...
 435:	00 00                	add    BYTE PTR [rax],al
 437:	00 64 00 00          	add    BYTE PTR [rax+rax*1+0x0],ah
 43b:	00 20                	add    BYTE PTR [rax],ah
	...
 44d:	00 00                	add    BYTE PTR [rax],al
 44f:	00 73 00             	add    BYTE PTR [rbx+0x0],dh
 452:	00 00                	add    BYTE PTR [rax],al
 454:	20 00                	and    BYTE PTR [rax],al
	...
 466:	00 00                	add    BYTE PTR [rax],al
 468:	01 00                	add    DWORD PTR [rax],eax
 46a:	00 00                	add    BYTE PTR [rax],al
 46c:	22 00                	and    al,BYTE PTR [rax]
	...

Disassembly of section .dynstr:

0000000000000480 <.dynstr>:
 480:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 483:	63 78 61             	movsxd edi,DWORD PTR [rax+0x61]
 486:	5f                   	pop    rdi
 487:	66 69 6e 61 6c 69    	imul   bp,WORD PTR [rsi+0x61],0x696c
 48d:	7a 65                	jp     4f4 <__abi_tag+0x168>
 48f:	00 5f 5f             	add    BYTE PTR [rdi+0x5f],bl
 492:	6c                   	ins    BYTE PTR es:[rdi],dx
 493:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
 49a:	72 74                	jb     510 <__abi_tag+0x184>
 49c:	5f                   	pop    rdi
 49d:	6d                   	ins    DWORD PTR es:[rdi],dx
 49e:	61                   	(bad)  
 49f:	69 6e 00 70 75 74 73 	imul   ebp,DWORD PTR [rsi+0x0],0x73747570
 4a6:	00 6c 69 62          	add    BYTE PTR [rcx+rbp*2+0x62],ch
 4aa:	63 2e                	movsxd ebp,DWORD PTR [rsi]
 4ac:	73 6f                	jae    51d <__abi_tag+0x191>
 4ae:	2e 36 00 47 4c       	cs ss add BYTE PTR [rdi+0x4c],al
 4b3:	49                   	rex.WB
 4b4:	42                   	rex.X
 4b5:	43 5f                	rex.XB pop r15
 4b7:	32 2e                	xor    ch,BYTE PTR [rsi]
 4b9:	32 2e                	xor    ch,BYTE PTR [rsi]
 4bb:	35 00 47 4c 49       	xor    eax,0x494c4700
 4c0:	42                   	rex.X
 4c1:	43 5f                	rex.XB pop r15
 4c3:	32 2e                	xor    ch,BYTE PTR [rsi]
 4c5:	33 34 00             	xor    esi,DWORD PTR [rax+rax*1]
 4c8:	5f                   	pop    rdi
 4c9:	49 54                	rex.WB push r12
 4cb:	4d 5f                	rex.WRB pop r15
 4cd:	64 65 72 65          	fs gs jb 536 <__abi_tag+0x1aa>
 4d1:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
 4d8:	4d 
 4d9:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
 4db:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 4dc:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 4dd:	65 54                	gs push rsp
 4df:	61                   	(bad)  
 4e0:	62                   	(bad)  
 4e1:	6c                   	ins    BYTE PTR es:[rdi],dx
 4e2:	65 00 5f 5f          	add    BYTE PTR gs:[rdi+0x5f],bl
 4e6:	67 6d                	ins    DWORD PTR es:[edi],dx
 4e8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 4e9:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 4ea:	5f                   	pop    rdi
 4eb:	73 74                	jae    561 <__abi_tag+0x1d5>
 4ed:	61                   	(bad)  
 4ee:	72 74                	jb     564 <__abi_tag+0x1d8>
 4f0:	5f                   	pop    rdi
 4f1:	5f                   	pop    rdi
 4f2:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 4f5:	54                   	push   rsp
 4f6:	4d 5f                	rex.WRB pop r15
 4f8:	72 65                	jb     55f <__abi_tag+0x1d3>
 4fa:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
 501:	4d 
 502:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
 504:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 505:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 506:	65 54                	gs push rsp
 508:	61                   	(bad)  
 509:	62                   	.byte 0x62
 50a:	6c                   	ins    BYTE PTR es:[rdi],dx
 50b:	65                   	gs
	...

Disassembly of section .gnu.version:

000000000000050e <.gnu.version>:
 50e:	00 00                	add    BYTE PTR [rax],al
 510:	02 00                	add    al,BYTE PTR [rax]
 512:	01 00                	add    DWORD PTR [rax],eax
 514:	03 00                	add    eax,DWORD PTR [rax]
 516:	01 00                	add    DWORD PTR [rax],eax
 518:	01 00                	add    DWORD PTR [rax],eax
 51a:	03 00                	add    eax,DWORD PTR [rax]

Disassembly of section .gnu.version_r:

0000000000000520 <.gnu.version_r>:
 520:	01 00                	add    DWORD PTR [rax],eax
 522:	02 00                	add    al,BYTE PTR [rax]
 524:	27                   	(bad)  
 525:	00 00                	add    BYTE PTR [rax],al
 527:	00 10                	add    BYTE PTR [rax],dl
 529:	00 00                	add    BYTE PTR [rax],al
 52b:	00 00                	add    BYTE PTR [rax],al
 52d:	00 00                	add    BYTE PTR [rax],al
 52f:	00 75 1a             	add    BYTE PTR [rbp+0x1a],dh
 532:	69 09 00 00 03 00    	imul   ecx,DWORD PTR [rcx],0x30000
 538:	31 00                	xor    DWORD PTR [rax],eax
 53a:	00 00                	add    BYTE PTR [rax],al
 53c:	10 00                	adc    BYTE PTR [rax],al
 53e:	00 00                	add    BYTE PTR [rax],al
 540:	b4 91                	mov    ah,0x91
 542:	96                   	xchg   esi,eax
 543:	06                   	(bad)  
 544:	00 00                	add    BYTE PTR [rax],al
 546:	02 00                	add    al,BYTE PTR [rax]
 548:	3d 00 00 00 00       	cmp    eax,0x0
 54d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000000550 <.rela.dyn>:
 550:	b8 3d 00 00 00       	mov    eax,0x3d
 555:	00 00                	add    BYTE PTR [rax],al
 557:	00 08                	add    BYTE PTR [rax],cl
 559:	00 00                	add    BYTE PTR [rax],al
 55b:	00 00                	add    BYTE PTR [rax],al
 55d:	00 00                	add    BYTE PTR [rax],al
 55f:	00 60 11             	add    BYTE PTR [rax+0x11],ah
 562:	00 00                	add    BYTE PTR [rax],al
 564:	00 00                	add    BYTE PTR [rax],al
 566:	00 00                	add    BYTE PTR [rax],al
 568:	c0 3d 00 00 00 00 00 	sar    BYTE PTR [rip+0x0],0x0        # 56f <__abi_tag+0x1e3>
 56f:	00 08                	add    BYTE PTR [rax],cl
 571:	00 00                	add    BYTE PTR [rax],al
 573:	00 00                	add    BYTE PTR [rax],al
 575:	00 00                	add    BYTE PTR [rax],al
 577:	00 20                	add    BYTE PTR [rax],ah
 579:	11 00                	adc    DWORD PTR [rax],eax
 57b:	00 00                	add    BYTE PTR [rax],al
 57d:	00 00                	add    BYTE PTR [rax],al
 57f:	00 08                	add    BYTE PTR [rax],cl
 581:	40 00 00             	rex add BYTE PTR [rax],al
 584:	00 00                	add    BYTE PTR [rax],al
 586:	00 00                	add    BYTE PTR [rax],al
 588:	08 00                	or     BYTE PTR [rax],al
 58a:	00 00                	add    BYTE PTR [rax],al
 58c:	00 00                	add    BYTE PTR [rax],al
 58e:	00 00                	add    BYTE PTR [rax],al
 590:	08 40 00             	or     BYTE PTR [rax+0x0],al
 593:	00 00                	add    BYTE PTR [rax],al
 595:	00 00                	add    BYTE PTR [rax],al
 597:	00 d8                	add    al,bl
 599:	3f                   	(bad)  
 59a:	00 00                	add    BYTE PTR [rax],al
 59c:	00 00                	add    BYTE PTR [rax],al
 59e:	00 00                	add    BYTE PTR [rax],al
 5a0:	06                   	(bad)  
 5a1:	00 00                	add    BYTE PTR [rax],al
 5a3:	00 01                	add    BYTE PTR [rcx],al
	...
 5ad:	00 00                	add    BYTE PTR [rax],al
 5af:	00 e0                	add    al,ah
 5b1:	3f                   	(bad)  
 5b2:	00 00                	add    BYTE PTR [rax],al
 5b4:	00 00                	add    BYTE PTR [rax],al
 5b6:	00 00                	add    BYTE PTR [rax],al
 5b8:	06                   	(bad)  
 5b9:	00 00                	add    BYTE PTR [rax],al
 5bb:	00 02                	add    BYTE PTR [rdx],al
	...
 5c5:	00 00                	add    BYTE PTR [rax],al
 5c7:	00 e8                	add    al,ch
 5c9:	3f                   	(bad)  
 5ca:	00 00                	add    BYTE PTR [rax],al
 5cc:	00 00                	add    BYTE PTR [rax],al
 5ce:	00 00                	add    BYTE PTR [rax],al
 5d0:	06                   	(bad)  
 5d1:	00 00                	add    BYTE PTR [rax],al
 5d3:	00 04 00             	add    BYTE PTR [rax+rax*1],al
	...
 5de:	00 00                	add    BYTE PTR [rax],al
 5e0:	f0 3f                	lock (bad) 
 5e2:	00 00                	add    BYTE PTR [rax],al
 5e4:	00 00                	add    BYTE PTR [rax],al
 5e6:	00 00                	add    BYTE PTR [rax],al
 5e8:	06                   	(bad)  
 5e9:	00 00                	add    BYTE PTR [rax],al
 5eb:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 5f1 <__abi_tag+0x265>
 5f1:	00 00                	add    BYTE PTR [rax],al
 5f3:	00 00                	add    BYTE PTR [rax],al
 5f5:	00 00                	add    BYTE PTR [rax],al
 5f7:	00 f8                	add    al,bh
 5f9:	3f                   	(bad)  
 5fa:	00 00                	add    BYTE PTR [rax],al
 5fc:	00 00                	add    BYTE PTR [rax],al
 5fe:	00 00                	add    BYTE PTR [rax],al
 600:	06                   	(bad)  
 601:	00 00                	add    BYTE PTR [rax],al
 603:	00 06                	add    BYTE PTR [rsi],al
	...

Disassembly of section .rela.plt:

0000000000000610 <.rela.plt>:
 610:	d0 3f                	sar    BYTE PTR [rdi],1
 612:	00 00                	add    BYTE PTR [rax],al
 614:	00 00                	add    BYTE PTR [rax],al
 616:	00 00                	add    BYTE PTR [rax],al
 618:	07                   	(bad)  
 619:	00 00                	add    BYTE PTR [rax],al
 61b:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 d9 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fd9]        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	push   QWORD PTR [rip+0x2f9a]        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 9b 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f9b]        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nop    DWORD PTR [rax]
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64 
    1044:	f2 ff 25 ad 2f 00 00 	bnd jmp QWORD PTR [rip+0x2fad]        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    104b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .plt.sec:

0000000000001050 <puts@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 75 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f75]        # 3fd0 <puts@GLIBC_2.2.5>
    105b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

0000000000001060 <main>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	48 83 ec 08          	sub    rsp,0x8
    1068:	48 8d 3d 95 0f 00 00 	lea    rdi,[rip+0xf95]        # 2004 <_IO_stdin_used+0x4>
    106f:	e8 dc ff ff ff       	call   1050 <puts@plt>
    1074:	31 c0                	xor    eax,eax
    1076:	48 83 c4 08          	add    rsp,0x8
    107a:	c3                   	ret    
    107b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001080 <_start>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	31 ed                	xor    ebp,ebp
    1086:	49 89 d1             	mov    r9,rdx
    1089:	5e                   	pop    rsi
    108a:	48 89 e2             	mov    rdx,rsp
    108d:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    1091:	50                   	push   rax
    1092:	54                   	push   rsp
    1093:	45 31 c0             	xor    r8d,r8d
    1096:	31 c9                	xor    ecx,ecx
    1098:	48 8d 3d c1 ff ff ff 	lea    rdi,[rip+0xffffffffffffffc1]        # 1060 <main>
    109f:	ff 15 33 2f 00 00    	call   QWORD PTR [rip+0x2f33]        # 3fd8 <__libc_start_main@GLIBC_2.34>
    10a5:	f4                   	hlt    
    10a6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    10ad:	00 00 00 

00000000000010b0 <deregister_tm_clones>:
    10b0:	48 8d 3d 59 2f 00 00 	lea    rdi,[rip+0x2f59]        # 4010 <__TMC_END__>
    10b7:	48 8d 05 52 2f 00 00 	lea    rax,[rip+0x2f52]        # 4010 <__TMC_END__>
    10be:	48 39 f8             	cmp    rax,rdi
    10c1:	74 15                	je     10d8 <deregister_tm_clones+0x28>
    10c3:	48 8b 05 16 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f16]        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    10ca:	48 85 c0             	test   rax,rax
    10cd:	74 09                	je     10d8 <deregister_tm_clones+0x28>
    10cf:	ff e0                	jmp    rax
    10d1:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    10d8:	c3                   	ret    
    10d9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010e0 <register_tm_clones>:
    10e0:	48 8d 3d 29 2f 00 00 	lea    rdi,[rip+0x2f29]        # 4010 <__TMC_END__>
    10e7:	48 8d 35 22 2f 00 00 	lea    rsi,[rip+0x2f22]        # 4010 <__TMC_END__>
    10ee:	48 29 fe             	sub    rsi,rdi
    10f1:	48 89 f0             	mov    rax,rsi
    10f4:	48 c1 ee 3f          	shr    rsi,0x3f
    10f8:	48 c1 f8 03          	sar    rax,0x3
    10fc:	48 01 c6             	add    rsi,rax
    10ff:	48 d1 fe             	sar    rsi,1
    1102:	74 14                	je     1118 <register_tm_clones+0x38>
    1104:	48 8b 05 e5 2e 00 00 	mov    rax,QWORD PTR [rip+0x2ee5]        # 3ff0 <_ITM_registerTMCloneTable@Base>
    110b:	48 85 c0             	test   rax,rax
    110e:	74 08                	je     1118 <register_tm_clones+0x38>
    1110:	ff e0                	jmp    rax
    1112:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1118:	c3                   	ret    
    1119:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001120 <__do_global_dtors_aux>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	80 3d e5 2e 00 00 00 	cmp    BYTE PTR [rip+0x2ee5],0x0        # 4010 <__TMC_END__>
    112b:	75 2b                	jne    1158 <__do_global_dtors_aux+0x38>
    112d:	55                   	push   rbp
    112e:	48 83 3d c2 2e 00 00 	cmp    QWORD PTR [rip+0x2ec2],0x0        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1135:	00 
    1136:	48 89 e5             	mov    rbp,rsp
    1139:	74 0c                	je     1147 <__do_global_dtors_aux+0x27>
    113b:	48 8b 3d c6 2e 00 00 	mov    rdi,QWORD PTR [rip+0x2ec6]        # 4008 <__dso_handle>
    1142:	e8 f9 fe ff ff       	call   1040 <__cxa_finalize@plt>
    1147:	e8 64 ff ff ff       	call   10b0 <deregister_tm_clones>
    114c:	c6 05 bd 2e 00 00 01 	mov    BYTE PTR [rip+0x2ebd],0x1        # 4010 <__TMC_END__>
    1153:	5d                   	pop    rbp
    1154:	c3                   	ret    
    1155:	0f 1f 00             	nop    DWORD PTR [rax]
    1158:	c3                   	ret    
    1159:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001160 <frame_dummy>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	e9 77 ff ff ff       	jmp    10e0 <register_tm_clones>

Disassembly of section .fini:

000000000000116c <_fini>:
    116c:	f3 0f 1e fa          	endbr64 
    1170:	48 83 ec 08          	sub    rsp,0x8
    1174:	48 83 c4 08          	add    rsp,0x8
    1178:	c3                   	ret    

Disassembly of section .rodata:

0000000000002000 <_IO_stdin_used>:
    2000:	01 00                	add    DWORD PTR [rax],eax
    2002:	02 00                	add    al,BYTE PTR [rax]
    2004:	68 65 6c 6c 6f       	push   0x6f6c6c65
    2009:	2c 20                	sub    al,0x20
    200b:	77 6f                	ja     207c <__GNU_EH_FRAME_HDR+0x68>
    200d:	72 6c                	jb     207b <__GNU_EH_FRAME_HDR+0x67>
    200f:	64                   	fs
	...

Disassembly of section .eh_frame_hdr:

0000000000002014 <__GNU_EH_FRAME_HDR>:
    2014:	01 1b                	add    DWORD PTR [rbx],ebx
    2016:	03 3b                	add    edi,DWORD PTR [rbx]
    2018:	30 00                	xor    BYTE PTR [rax],al
    201a:	00 00                	add    BYTE PTR [rax],al
    201c:	05 00 00 00 0c       	add    eax,0xc000000
    2021:	f0 ff                	lock (bad) 
    2023:	ff 64 00 00          	jmp    QWORD PTR [rax+rax*1+0x0]
    2027:	00 2c f0             	add    BYTE PTR [rax+rsi*8],ch
    202a:	ff                   	(bad)  
    202b:	ff 8c 00 00 00 3c f0 	dec    DWORD PTR [rax+rax*1-0xfc40000]
    2032:	ff                   	(bad)  
    2033:	ff a4 00 00 00 4c f0 	jmp    QWORD PTR [rax+rax*1-0xfb40000]
    203a:	ff                   	(bad)  
    203b:	ff                   	(bad)  
    203c:	bc 00 00 00 6c       	mov    esp,0x6c000000
    2041:	f0 ff                	lock (bad) 
    2043:	ff 4c 00 00          	dec    DWORD PTR [rax+rax*1+0x0]
	...

Disassembly of section .eh_frame:

0000000000002048 <__FRAME_END__-0xa0>:
    2048:	14 00                	adc    al,0x0
    204a:	00 00                	add    BYTE PTR [rax],al
    204c:	00 00                	add    BYTE PTR [rax],al
    204e:	00 00                	add    BYTE PTR [rax],al
    2050:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
    2053:	00 01                	add    BYTE PTR [rcx],al
    2055:	78 10                	js     2067 <__GNU_EH_FRAME_HDR+0x53>
    2057:	01 1b                	add    DWORD PTR [rbx],ebx
    2059:	0c 07                	or     al,0x7
    205b:	08 90 01 00 00 14    	or     BYTE PTR [rax+0x14000001],dl
    2061:	00 00                	add    BYTE PTR [rax],al
    2063:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
    2066:	00 00                	add    BYTE PTR [rax],al
    2068:	18 f0                	sbb    al,dh
    206a:	ff                   	(bad)  
    206b:	ff 26                	jmp    QWORD PTR [rsi]
    206d:	00 00                	add    BYTE PTR [rax],al
    206f:	00 00                	add    BYTE PTR [rax],al
    2071:	44 07                	rex.R (bad) 
    2073:	10 00                	adc    BYTE PTR [rax],al
    2075:	00 00                	add    BYTE PTR [rax],al
    2077:	00 24 00             	add    BYTE PTR [rax+rax*1],ah
    207a:	00 00                	add    BYTE PTR [rax],al
    207c:	34 00                	xor    al,0x0
    207e:	00 00                	add    BYTE PTR [rax],al
    2080:	a0 ef ff ff 20 00 00 	movabs al,ds:0x20ffffef
    2087:	00 00 
    2089:	0e                   	(bad)  
    208a:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
    208d:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
    2090:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
    2093:	80 00 3f             	add    BYTE PTR [rax],0x3f
    2096:	1a 3a                	sbb    bh,BYTE PTR [rdx]
    2098:	2a 33                	sub    dh,BYTE PTR [rbx]
    209a:	24 22                	and    al,0x22
    209c:	00 00                	add    BYTE PTR [rax],al
    209e:	00 00                	add    BYTE PTR [rax],al
    20a0:	14 00                	adc    al,0x0
    20a2:	00 00                	add    BYTE PTR [rax],al
    20a4:	5c                   	pop    rsp
    20a5:	00 00                	add    BYTE PTR [rax],al
    20a7:	00 98 ef ff ff 10    	add    BYTE PTR [rax+0x10ffffef],bl
	...
    20b5:	00 00                	add    BYTE PTR [rax],al
    20b7:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
    20ba:	00 00                	add    BYTE PTR [rax],al
    20bc:	74 00                	je     20be <__GNU_EH_FRAME_HDR+0xaa>
    20be:	00 00                	add    BYTE PTR [rax],al
    20c0:	90                   	nop
    20c1:	ef                   	out    dx,eax
    20c2:	ff                   	(bad)  
    20c3:	ff 10                	call   QWORD PTR [rax]
	...
    20cd:	00 00                	add    BYTE PTR [rax],al
    20cf:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
    20d2:	00 00                	add    BYTE PTR [rax],al
    20d4:	8c 00                	mov    WORD PTR [rax],es
    20d6:	00 00                	add    BYTE PTR [rax],al
    20d8:	88 ef                	mov    bh,ch
    20da:	ff                   	(bad)  
    20db:	ff 1b                	call   FWORD PTR [rbx]
    20dd:	00 00                	add    BYTE PTR [rax],al
    20df:	00 00                	add    BYTE PTR [rax],al
    20e1:	48 0e                	rex.W (bad) 
    20e3:	10 52 0e             	adc    BYTE PTR [rdx+0xe],dl
    20e6:	08 00                	or     BYTE PTR [rax],al

00000000000020e8 <__FRAME_END__>:
    20e8:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000003db8 <__frame_dummy_init_array_entry>:
    3db8:	60                   	(bad)  
    3db9:	11 00                	adc    DWORD PTR [rax],eax
    3dbb:	00 00                	add    BYTE PTR [rax],al
    3dbd:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .fini_array:

0000000000003dc0 <__do_global_dtors_aux_fini_array_entry>:
    3dc0:	20 11                	and    BYTE PTR [rcx],dl
    3dc2:	00 00                	add    BYTE PTR [rax],al
    3dc4:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .dynamic:

0000000000003dc8 <_DYNAMIC>:
    3dc8:	01 00                	add    DWORD PTR [rax],eax
    3dca:	00 00                	add    BYTE PTR [rax],al
    3dcc:	00 00                	add    BYTE PTR [rax],al
    3dce:	00 00                	add    BYTE PTR [rax],al
    3dd0:	27                   	(bad)  
    3dd1:	00 00                	add    BYTE PTR [rax],al
    3dd3:	00 00                	add    BYTE PTR [rax],al
    3dd5:	00 00                	add    BYTE PTR [rax],al
    3dd7:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
    3dda:	00 00                	add    BYTE PTR [rax],al
    3ddc:	00 00                	add    BYTE PTR [rax],al
    3dde:	00 00                	add    BYTE PTR [rax],al
    3de0:	00 10                	add    BYTE PTR [rax],dl
    3de2:	00 00                	add    BYTE PTR [rax],al
    3de4:	00 00                	add    BYTE PTR [rax],al
    3de6:	00 00                	add    BYTE PTR [rax],al
    3de8:	0d 00 00 00 00       	or     eax,0x0
    3ded:	00 00                	add    BYTE PTR [rax],al
    3def:	00 6c 11 00          	add    BYTE PTR [rcx+rdx*1+0x0],ch
    3df3:	00 00                	add    BYTE PTR [rax],al
    3df5:	00 00                	add    BYTE PTR [rax],al
    3df7:	00 19                	add    BYTE PTR [rcx],bl
    3df9:	00 00                	add    BYTE PTR [rax],al
    3dfb:	00 00                	add    BYTE PTR [rax],al
    3dfd:	00 00                	add    BYTE PTR [rax],al
    3dff:	00 b8 3d 00 00 00    	add    BYTE PTR [rax+0x3d],bh
    3e05:	00 00                	add    BYTE PTR [rax],al
    3e07:	00 1b                	add    BYTE PTR [rbx],bl
    3e09:	00 00                	add    BYTE PTR [rax],al
    3e0b:	00 00                	add    BYTE PTR [rax],al
    3e0d:	00 00                	add    BYTE PTR [rax],al
    3e0f:	00 08                	add    BYTE PTR [rax],cl
    3e11:	00 00                	add    BYTE PTR [rax],al
    3e13:	00 00                	add    BYTE PTR [rax],al
    3e15:	00 00                	add    BYTE PTR [rax],al
    3e17:	00 1a                	add    BYTE PTR [rdx],bl
    3e19:	00 00                	add    BYTE PTR [rax],al
    3e1b:	00 00                	add    BYTE PTR [rax],al
    3e1d:	00 00                	add    BYTE PTR [rax],al
    3e1f:	00 c0                	add    al,al
    3e21:	3d 00 00 00 00       	cmp    eax,0x0
    3e26:	00 00                	add    BYTE PTR [rax],al
    3e28:	1c 00                	sbb    al,0x0
    3e2a:	00 00                	add    BYTE PTR [rax],al
    3e2c:	00 00                	add    BYTE PTR [rax],al
    3e2e:	00 00                	add    BYTE PTR [rax],al
    3e30:	08 00                	or     BYTE PTR [rax],al
    3e32:	00 00                	add    BYTE PTR [rax],al
    3e34:	00 00                	add    BYTE PTR [rax],al
    3e36:	00 00                	add    BYTE PTR [rax],al
    3e38:	f5                   	cmc    
    3e39:	fe                   	(bad)  
    3e3a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3e3d:	00 00                	add    BYTE PTR [rax],al
    3e3f:	00 b0 03 00 00 00    	add    BYTE PTR [rax+0x3],dh
    3e45:	00 00                	add    BYTE PTR [rax],al
    3e47:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 3e4d <_DYNAMIC+0x85>
    3e4d:	00 00                	add    BYTE PTR [rax],al
    3e4f:	00 80 04 00 00 00    	add    BYTE PTR [rax+0x4],al
    3e55:	00 00                	add    BYTE PTR [rax],al
    3e57:	00 06                	add    BYTE PTR [rsi],al
    3e59:	00 00                	add    BYTE PTR [rax],al
    3e5b:	00 00                	add    BYTE PTR [rax],al
    3e5d:	00 00                	add    BYTE PTR [rax],al
    3e5f:	00 d8                	add    al,bl
    3e61:	03 00                	add    eax,DWORD PTR [rax]
    3e63:	00 00                	add    BYTE PTR [rax],al
    3e65:	00 00                	add    BYTE PTR [rax],al
    3e67:	00 0a                	add    BYTE PTR [rdx],cl
    3e69:	00 00                	add    BYTE PTR [rax],al
    3e6b:	00 00                	add    BYTE PTR [rax],al
    3e6d:	00 00                	add    BYTE PTR [rax],al
    3e6f:	00 8d 00 00 00 00    	add    BYTE PTR [rbp+0x0],cl
    3e75:	00 00                	add    BYTE PTR [rax],al
    3e77:	00 0b                	add    BYTE PTR [rbx],cl
    3e79:	00 00                	add    BYTE PTR [rax],al
    3e7b:	00 00                	add    BYTE PTR [rax],al
    3e7d:	00 00                	add    BYTE PTR [rax],al
    3e7f:	00 18                	add    BYTE PTR [rax],bl
    3e81:	00 00                	add    BYTE PTR [rax],al
    3e83:	00 00                	add    BYTE PTR [rax],al
    3e85:	00 00                	add    BYTE PTR [rax],al
    3e87:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 3e8d <_DYNAMIC+0xc5>
	...
    3e95:	00 00                	add    BYTE PTR [rax],al
    3e97:	00 03                	add    BYTE PTR [rbx],al
    3e99:	00 00                	add    BYTE PTR [rax],al
    3e9b:	00 00                	add    BYTE PTR [rax],al
    3e9d:	00 00                	add    BYTE PTR [rax],al
    3e9f:	00 b8 3f 00 00 00    	add    BYTE PTR [rax+0x3f],bh
    3ea5:	00 00                	add    BYTE PTR [rax],al
    3ea7:	00 02                	add    BYTE PTR [rdx],al
    3ea9:	00 00                	add    BYTE PTR [rax],al
    3eab:	00 00                	add    BYTE PTR [rax],al
    3ead:	00 00                	add    BYTE PTR [rax],al
    3eaf:	00 18                	add    BYTE PTR [rax],bl
    3eb1:	00 00                	add    BYTE PTR [rax],al
    3eb3:	00 00                	add    BYTE PTR [rax],al
    3eb5:	00 00                	add    BYTE PTR [rax],al
    3eb7:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
    3eba:	00 00                	add    BYTE PTR [rax],al
    3ebc:	00 00                	add    BYTE PTR [rax],al
    3ebe:	00 00                	add    BYTE PTR [rax],al
    3ec0:	07                   	(bad)  
    3ec1:	00 00                	add    BYTE PTR [rax],al
    3ec3:	00 00                	add    BYTE PTR [rax],al
    3ec5:	00 00                	add    BYTE PTR [rax],al
    3ec7:	00 17                	add    BYTE PTR [rdi],dl
    3ec9:	00 00                	add    BYTE PTR [rax],al
    3ecb:	00 00                	add    BYTE PTR [rax],al
    3ecd:	00 00                	add    BYTE PTR [rax],al
    3ecf:	00 10                	add    BYTE PTR [rax],dl
    3ed1:	06                   	(bad)  
    3ed2:	00 00                	add    BYTE PTR [rax],al
    3ed4:	00 00                	add    BYTE PTR [rax],al
    3ed6:	00 00                	add    BYTE PTR [rax],al
    3ed8:	07                   	(bad)  
    3ed9:	00 00                	add    BYTE PTR [rax],al
    3edb:	00 00                	add    BYTE PTR [rax],al
    3edd:	00 00                	add    BYTE PTR [rax],al
    3edf:	00 50 05             	add    BYTE PTR [rax+0x5],dl
    3ee2:	00 00                	add    BYTE PTR [rax],al
    3ee4:	00 00                	add    BYTE PTR [rax],al
    3ee6:	00 00                	add    BYTE PTR [rax],al
    3ee8:	08 00                	or     BYTE PTR [rax],al
    3eea:	00 00                	add    BYTE PTR [rax],al
    3eec:	00 00                	add    BYTE PTR [rax],al
    3eee:	00 00                	add    BYTE PTR [rax],al
    3ef0:	c0 00 00             	rol    BYTE PTR [rax],0x0
    3ef3:	00 00                	add    BYTE PTR [rax],al
    3ef5:	00 00                	add    BYTE PTR [rax],al
    3ef7:	00 09                	add    BYTE PTR [rcx],cl
    3ef9:	00 00                	add    BYTE PTR [rax],al
    3efb:	00 00                	add    BYTE PTR [rax],al
    3efd:	00 00                	add    BYTE PTR [rax],al
    3eff:	00 18                	add    BYTE PTR [rax],bl
    3f01:	00 00                	add    BYTE PTR [rax],al
    3f03:	00 00                	add    BYTE PTR [rax],al
    3f05:	00 00                	add    BYTE PTR [rax],al
    3f07:	00 1e                	add    BYTE PTR [rsi],bl
    3f09:	00 00                	add    BYTE PTR [rax],al
    3f0b:	00 00                	add    BYTE PTR [rax],al
    3f0d:	00 00                	add    BYTE PTR [rax],al
    3f0f:	00 08                	add    BYTE PTR [rax],cl
    3f11:	00 00                	add    BYTE PTR [rax],al
    3f13:	00 00                	add    BYTE PTR [rax],al
    3f15:	00 00                	add    BYTE PTR [rax],al
    3f17:	00 fb                	add    bl,bh
    3f19:	ff                   	(bad)  
    3f1a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f1d:	00 00                	add    BYTE PTR [rax],al
    3f1f:	00 01                	add    BYTE PTR [rcx],al
    3f21:	00 00                	add    BYTE PTR [rax],al
    3f23:	08 00                	or     BYTE PTR [rax],al
    3f25:	00 00                	add    BYTE PTR [rax],al
    3f27:	00 fe                	add    dh,bh
    3f29:	ff                   	(bad)  
    3f2a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f2d:	00 00                	add    BYTE PTR [rax],al
    3f2f:	00 20                	add    BYTE PTR [rax],ah
    3f31:	05 00 00 00 00       	add    eax,0x0
    3f36:	00 00                	add    BYTE PTR [rax],al
    3f38:	ff                   	(bad)  
    3f39:	ff                   	(bad)  
    3f3a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f3d:	00 00                	add    BYTE PTR [rax],al
    3f3f:	00 01                	add    BYTE PTR [rcx],al
    3f41:	00 00                	add    BYTE PTR [rax],al
    3f43:	00 00                	add    BYTE PTR [rax],al
    3f45:	00 00                	add    BYTE PTR [rax],al
    3f47:	00 f0                	add    al,dh
    3f49:	ff                   	(bad)  
    3f4a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f4d:	00 00                	add    BYTE PTR [rax],al
    3f4f:	00 0e                	add    BYTE PTR [rsi],cl
    3f51:	05 00 00 00 00       	add    eax,0x0
    3f56:	00 00                	add    BYTE PTR [rax],al
    3f58:	f9                   	stc    
    3f59:	ff                   	(bad)  
    3f5a:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f5d:	00 00                	add    BYTE PTR [rax],al
    3f5f:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .got:

0000000000003fb8 <_GLOBAL_OFFSET_TABLE_>:
    3fb8:	c8 3d 00 00          	enter  0x3d,0x0
	...
    3fd0:	30 10                	xor    BYTE PTR [rax],dl
	...

Disassembly of section .data:

0000000000004000 <__data_start>:
	...

0000000000004008 <__dso_handle>:
    4008:	08 40 00             	or     BYTE PTR [rax+0x0],al
    400b:	00 00                	add    BYTE PTR [rax],al
    400d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .bss:

0000000000004010 <completed.0>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 55 62             	sub    BYTE PTR [rbp+0x62],dl
   8:	75 6e                	jne    78 <__abi_tag-0x314>
   a:	74 75                	je     81 <__abi_tag-0x30b>
   c:	20 31                	and    BYTE PTR [rcx],dh
   e:	31 2e                	xor    DWORD PTR [rsi],ebp
  10:	34 2e                	xor    al,0x2e
  12:	30 2d 31 75 62 75    	xor    BYTE PTR [rip+0x75627531],ch        # 75627549 <_end+0x75623531>
  18:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  19:	74 75                	je     90 <__abi_tag-0x2fc>
  1b:	31 7e 32             	xor    DWORD PTR [rsi+0x32],edi
  1e:	32 2e                	xor    ch,BYTE PTR [rsi]
  20:	30 34 29             	xor    BYTE PTR [rcx+rbp*1],dh
  23:	20 31                	and    BYTE PTR [rcx],dh
  25:	31 2e                	xor    DWORD PTR [rsi],ebp
  27:	34 2e                	xor    al,0x2e
  29:	30 00                	xor    BYTE PTR [rax],al
