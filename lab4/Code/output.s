.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text

read:
	li $v0, 4
	la $a0, _prompt
	syscall
	li $v0, 5
	syscall
	jr $ra

write:
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, _ret
	syscall
	move $v0, $0
	jr $ra

func:
	subu $sp, $sp, 4
	sw $fp, 0($sp)
	move $fp, $sp
	addi $sp, $fp, -2048
	sw $t0, -20($fp)
	sw $t0, -24($fp)
	lw $t1, -24($fp)
	addi $t0, $fp, -24 
	sw $t0, -28($fp)
	li $t0, 0
	sw $t0, -32($fp)
	lw $t0, -32($fp)
	li $t1, 4
	mul $t0, $t0, $t1
	sw $t0, -32($fp)
	lw $t1, -28($fp)
	lw $t2, -32($fp)
	add $t0, $t1, $t2
	sw $t0, -36($fp)
	li $t0, 1
	sw $t0, -40($fp)
	lw $t0, -36($fp)
	lw $t1, -40($fp)
	sw $t1, 0($t0) 
	sw $t0, -36($fp)
	lw $t1, -24($fp)
	addi $t0, $fp, -24 
	sw $t0, -44($fp)
	lw $t1, -24($fp)
	addi $t0, $fp, -24 
	sw $t0, -48($fp)
	li $t0, 0
	sw $t0, -52($fp)
	lw $t0, -52($fp)
	li $t1, 4
	mul $t0, $t0, $t1
	sw $t0, -52($fp)
	lw $t1, -48($fp)
	lw $t2, -52($fp)
	add $t0, $t1, $t2
	sw $t0, -56($fp)
	lw $t1, -56($fp)
	lw $t0, 0($t1) 
	sw $t0, -60($fp)
	li $t0, 2
	sw $t0, -64($fp)
	lw $t1, -60($fp)
	lw $t2, -64($fp)
	add $t0, $t1, $t2
	sw $t0, -68($fp)
	lw $t0, -68($fp)
	li $t1, 4
	mul $t0, $t0, $t1
	sw $t0, -68($fp)
	lw $t1, -44($fp)
	lw $t2, -68($fp)
	add $t0, $t1, $t2
	sw $t0, -72($fp)
	li $t0, 9
	sw $t0, -76($fp)
	lw $t0, -72($fp)
	lw $t1, -76($fp)
	sw $t1, 0($t0) 
	sw $t0, -72($fp)
	lw $t1, -24($fp)
	addi $t0, $fp, -24 
	sw $t0, -80($fp)
	li $t0, 3
	sw $t0, -84($fp)
	lw $t0, -84($fp)
	li $t1, 4
	mul $t0, $t0, $t1
	sw $t0, -84($fp)
	lw $t1, -80($fp)
	lw $t2, -84($fp)
	add $t0, $t1, $t2
	sw $t0, -88($fp)
	lw $t1, -88($fp)
	lw $t0, 0($t1) 
	sw $t0, -92($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	lw $t0, -92($fp)
	move $a0, $t0
	jal write
	sw $t0, -92($fp)
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	li $t0, 0
	sw $t0, -96($fp)
	lw $t0, -96($fp)
	move $v0, $t0
	addi $sp, $sp, 2048
	lw $fp, 0($sp)
	addi $sp, $sp, 4
	jr $ra
main:
	subu $sp, $sp, 4
	sw $fp, 0($sp)
	move $fp, $sp
	addi $sp, $fp, -2048
	li $v1,0
	subu $sp, $sp, 4
	sw $v1, 0($sp)
	subu $sp, $sp, 4
	sw $ra, 0($sp)
	jal func
	move $t0, $v0
	sw $t0, -4($fp)
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $v1, 0($sp)
	addi $sp, $sp, 4
	add $sp, $sp, $v1
	li $t0, 0
	sw $t0, -8($fp)
	lw $t0, -8($fp)
	move $v0, $t0
	addi $sp, $sp, 2048
	lw $fp, 0($sp)
	addi $sp, $sp, 4
	jr $ra
