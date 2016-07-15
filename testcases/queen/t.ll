@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@n = common global i32 0, align 4
@ans = global i32 0, align 4
@b = common global [20 x i32] zeroinitializer, align 4
@l = common global [40 x i32] zeroinitializer, align 4
@r = common global [40 x i32] zeroinitializer, align 4

define i32 @dfs(i32 %x) #0
{
entry:
  %x.addr = alloca i32, align 4
  store i32 %x, i32* %x.addr, align 4
  %i = alloca i32, align 4
  %r0 = load i32* %x.addr, align 4
  %r1 = load i32* @n, align 4
  %r2 = icmp eq i32 %r0, %r1
  br i1 %r2, label %if0.then, label %if0.end

if0.then:
  %r3 = load i32* @ans, align 4
  %r4 = add nsw i32 %r3, 1
  store i32 %r4, i32* @ans, align 4
  %r5 = alloca i32, align 4
  store i32 0, i32* %r5
  %r6 = load i32* %r5
  ret i32 %r6
  br label %if0.end

if0.end:
  store i32 0, i32* %i, align 4
  br label %for0.cond

for0.cond:
  %r7 = load i32* %i, align 4
  %r8 = load i32* @n, align 4
  %r9 = icmp slt i32 %r7, %r8
  br i1 %r9, label %for0.body, label %for0.end

for0.body:
  %r10 = load i32* %i, align 4
  %arrayidx0 = getelementptr inbounds [20 x i32]* @b, i32 0, i32 %r10
  %r11 = load i32* %arrayidx0, align 4
  %r12 = icmp eq i32 %r11, 0
  %r13 = load i32* %i, align 4
  %r14 = load i32* %x.addr, align 4
  %r15 = add nsw i32 %r13, %r14
  %arrayidx1 = getelementptr inbounds [40 x i32]* @l, i32 0, i32 %r15
  %r16 = load i32* %arrayidx1, align 4
  %r17 = icmp eq i32 %r16, 0
  %r18 = icmp ne i1 %r12, 0
  %r19 = icmp ne i1 %r17, 0
  %r20 = and i1 %r18, %r19
  %r21 = load i32* %i, align 4
  %r22 = load i32* %x.addr, align 4
  %r23 = sub nsw i32 %r21, %r22
  %r24 = load i32* @n, align 4
  %r25 = sub nsw i32 %r24, 1
  %r26 = add nsw i32 %r23, %r25
  %arrayidx2 = getelementptr inbounds [40 x i32]* @r, i32 0, i32 %r26
  %r27 = load i32* %arrayidx2, align 4
  %r28 = icmp eq i32 %r27, 0
  %r29 = icmp ne i1 %r20, 0
  %r30 = icmp ne i1 %r28, 0
  %r31 = and i1 %r29, %r30
  br i1 %r31, label %if1.then, label %if1.end

if1.then:
  %r32 = load i32* %i, align 4
  %arrayidx3 = getelementptr inbounds [20 x i32]* @b, i32 0, i32 %r32
  store i32 1, i32* %arrayidx3, align 4
  %r33 = load i32* %i, align 4
  %r34 = load i32* %x.addr, align 4
  %r35 = add nsw i32 %r33, %r34
  %arrayidx4 = getelementptr inbounds [40 x i32]* @l, i32 0, i32 %r35
  store i32 1, i32* %arrayidx4, align 4
  %r36 = load i32* %i, align 4
  %r37 = load i32* %x.addr, align 4
  %r38 = sub nsw i32 %r36, %r37
  %r39 = load i32* @n, align 4
  %r40 = sub nsw i32 %r39, 1
  %r41 = add nsw i32 %r38, %r40
  %arrayidx5 = getelementptr inbounds [40 x i32]* @r, i32 0, i32 %r41
  store i32 1, i32* %arrayidx5, align 4
  %r42 = load i32* %x.addr, align 4
  %r43 = add nsw i32 %r42, 1
  %call0 = call i32 @dfs(i32 %r43)
  %r44 = load i32* %i, align 4
  %arrayidx6 = getelementptr inbounds [20 x i32]* @b, i32 0, i32 %r44
  store i32 0, i32* %arrayidx6, align 4
  %r45 = load i32* %i, align 4
  %r46 = load i32* %x.addr, align 4
  %r47 = add nsw i32 %r45, %r46
  %arrayidx7 = getelementptr inbounds [40 x i32]* @l, i32 0, i32 %r47
  store i32 0, i32* %arrayidx7, align 4
  %r48 = load i32* %i, align 4
  %r49 = load i32* %x.addr, align 4
  %r50 = sub nsw i32 %r48, %r49
  %r51 = load i32* @n, align 4
  %r52 = sub nsw i32 %r51, 1
  %r53 = add nsw i32 %r50, %r52
  %arrayidx8 = getelementptr inbounds [40 x i32]* @r, i32 0, i32 %r53
  store i32 0, i32* %arrayidx8, align 4
  br label %if1.end

if1.end:
  br label %for0.inc

for0.inc:
  %r54 = load i32* %i, align 4
  %r55 = add nsw i32 %r54, 1
  store i32 %r55, i32* %i, align 4
  br label %for0.cond

for0.end:
  %r56 = alloca i32, align 4
  store i32 0, i32* %r56
  %r57 = load i32* %r56
  ret i32 %r57
}

define i32 @main() #0
{
entry:
  %call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @n)
  %r0 = load i32* @n, align 4
  %r1 = icmp sgt i32 %r0, 16
  br i1 %r1, label %if0.then, label %if0.else

if0.then:
  %call1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 -1)
  %call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  br label %if0.end

if0.else:
  %call3 = call i32 @dfs(i32 0)
  %r2 = load i32* @ans, align 4
  %call4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %r2)
  %call5 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  br label %if0.end

if0.end:
  %r3 = alloca i32, align 4
  store i32 0, i32* %r3
  %r4 = load i32* %r3
  ret i32 %r4
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
