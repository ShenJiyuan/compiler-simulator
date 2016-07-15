@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@mat = global [4 x i32] [i32 0, i32 1, i32 1, i32 1], align 4
@n = common global i32 0, align 4
@MOD = global i32 10007, align 4

define i32 @solve(i32 %x) #0
{
entry:
  %x.addr = alloca i32, align 4
  store i32 %x, i32* %x.addr, align 4
  %p = alloca i32, align 4
  %q = alloca i32, align 4
  %r = alloca i32, align 4
  %s = alloca i32, align 4
  %ans = alloca [2 x i32], align 4
  %arrayidx0 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  store i32 0, i32* %arrayidx0, align 4
  %arrayidx1 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  store i32 1, i32* %arrayidx1, align 4
  br label %for0.cond

for0.cond:
  %r0 = load i32* %x.addr, align 4
  %r1 = icmp sgt i32 %r0, 0  br i1 %r1, label %for0.body, label %for0.end

for0.body:
  %r2 = load i32* %x.addr, align 4
  %r3 = and i32 %r2, 1
  %r4 = icmp ne i32 %r3, 0
  br i1 %r4, label %if0.then, label %if0.end

if0.then:
  %arrayidx2 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  %r5 = load i32* %arrayidx2, align 4
  %arrayidx3 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
  %r6 = load i32* %arrayidx3, align 4
  %r7 = mul nsw i32 %r5, %r6
  %arrayidx4 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  %r8 = load i32* %arrayidx4, align 4
  %arrayidx5 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
  %r9 = load i32* %arrayidx5, align 4
  %r10 = mul nsw i32 %r8, %r9
  %r11 = add nsw i32 %r7, %r10
  store i32 %r11, i32* %p, align 4
  %arrayidx6 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  %r12 = load i32* %arrayidx6, align 4
  %arrayidx7 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
  %r13 = load i32* %arrayidx7, align 4
  %r14 = mul nsw i32 %r12, %r13
  %arrayidx8 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  %r15 = load i32* %arrayidx8, align 4
  %arrayidx9 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
  %r16 = load i32* %arrayidx9, align 4
  %r17 = mul nsw i32 %r15, %r16
  %r18 = add nsw i32 %r14, %r17
  store i32 %r18, i32* %q, align 4
  %r19 = load i32* %p, align 4
  %r20 = load i32* @MOD, align 4
  %r21 = srem i32 %r19, %r20
  %arrayidx10 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  store i32 %r21, i32* %arrayidx10, align 4
  %r22 = load i32* %q, align 4
  %r23 = load i32* @MOD, align 4
  %r24 = srem i32 %r22, %r23
  %arrayidx11 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  store i32 %r24, i32* %arrayidx11, align 4
  br label %if0.end

if0.end:
  %arrayidx12 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
  %r25 = load i32* %arrayidx12, align 4
  %arrayidx13 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
  %r26 = load i32* %arrayidx13, align 4
  %r27 = mul nsw i32 %r25, %r26
  %arrayidx14 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
  %r28 = load i32* %arrayidx14, align 4
  %arrayidx15 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
  %r29 = load i32* %arrayidx15, align 4
  %r30 = mul nsw i32 %r28, %r29
  %r31 = add nsw i32 %r27, %r30
  store i32 %r31, i32* %p, align 4
  %arrayidx16 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
  %r32 = load i32* %arrayidx16, align 4
  %arrayidx17 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
  %r33 = load i32* %arrayidx17, align 4
  %r34 = mul nsw i32 %r32, %r33
  %arrayidx18 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
  %r35 = load i32* %arrayidx18, align 4
  %arrayidx19 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
  %r36 = load i32* %arrayidx19, align 4
  %r37 = mul nsw i32 %r35, %r36
  %r38 = add nsw i32 %r34, %r37
  store i32 %r38, i32* %q, align 4
  %arrayidx20 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
  %r39 = load i32* %arrayidx20, align 4
  %arrayidx21 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
  %r40 = load i32* %arrayidx21, align 4
  %r41 = mul nsw i32 %r39, %r40
  %arrayidx22 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
  %r42 = load i32* %arrayidx22, align 4
  %arrayidx23 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
  %r43 = load i32* %arrayidx23, align 4
  %r44 = mul nsw i32 %r42, %r43
  %r45 = add nsw i32 %r41, %r44
  store i32 %r45, i32* %r, align 4
  %arrayidx24 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
  %r46 = load i32* %arrayidx24, align 4
  %arrayidx25 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
  %r47 = load i32* %arrayidx25, align 4
  %r48 = mul nsw i32 %r46, %r47
  %arrayidx26 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
  %r49 = load i32* %arrayidx26, align 4
  %arrayidx27 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
  %r50 = load i32* %arrayidx27, align 4
  %r51 = mul nsw i32 %r49, %r50
  %r52 = add nsw i32 %r48, %r51
  store i32 %r52, i32* %s, align 4
  %r53 = load i32* %p, align 4
  %r54 = load i32* @MOD, align 4
  %r55 = srem i32 %r53, %r54
  %arrayidx28 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 0
  store i32 %r55, i32* %arrayidx28, align 4
  %r56 = load i32* %q, align 4
  %r57 = load i32* @MOD, align 4
  %r58 = srem i32 %r56, %r57
  %arrayidx29 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 1
  store i32 %r58, i32* %arrayidx29, align 4
  %r59 = load i32* %r, align 4
  %r60 = load i32* @MOD, align 4
  %r61 = srem i32 %r59, %r60
  %arrayidx30 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 2
  store i32 %r61, i32* %arrayidx30, align 4
  %r62 = load i32* %s, align 4
  %r63 = load i32* @MOD, align 4
  %r64 = srem i32 %r62, %r63
  %arrayidx31 = getelementptr inbounds [4 x i32]* @mat, i32 0, i32 3
  store i32 %r64, i32* %arrayidx31, align 4
  br label %for0.inc

for0.inc:
%r65 = load i32* %x.addr, align 4
  %r66 = ashr i32 %r65, 1
  store i32 %r66, i32* %x.addr, align 4
  br label %for0.cond

for0.end:
  %r67 = alloca i32, align 4
  %arrayidx32 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  %r68 = load i32* %arrayidx32, align 4
  store i32 %r68, i32* %r67
  %r69 = load i32* %r67
  ret i32 %r69
}

define i32 @main() #0
{
entry:
  %call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @n)
  %r0 = load i32* @n, align 4
  %call1 = call i32 @solve(i32 %r0)
  %call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %call1)
  %call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  %r1 = alloca i32, align 4
  store i32 0, i32* %r1
  %r2 = load i32* %r1
  ret i32 %r2
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
