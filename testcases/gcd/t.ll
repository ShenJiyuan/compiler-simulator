@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@a = common global i32 0, align 4
@b = common global i32 0, align 4

define i32 @gcd(i32 %x, i32 %y) #0
{
entry:
  %x.addr = alloca i32, align 4
  store i32 %x, i32* %x.addr, align 4
  %y.addr = alloca i32, align 4
  store i32 %y, i32* %y.addr, align 4
  %r0 = load i32* %y.addr, align 4
  %r1 = icmp eq i32 %r0, 0
  br i1 %r1, label %if0.then, label %if0.end

if0.then:
  %r2 = alloca i32, align 4
  %r3 = load i32* %x.addr, align 4
  store i32 %r3, i32* %r2
  %r4 = load i32* %r2
  ret i32 %r4
  br label %if0.end

if0.end:
  %r5 = alloca i32, align 4
  %r6 = load i32* %y.addr, align 4
  %r7 = load i32* %x.addr, align 4
  %r8 = load i32* %y.addr, align 4
  %r9 = srem i32 %r7, %r8
  %call0 = call i32 @gcd(i32 %r6, i32 %r9)
  store i32 %call0, i32* %r5
  %r10 = load i32* %r5
  ret i32 %r10
}

define i32 @main() #0
{
entry:
  %call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @a)
  %call1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @b)
  %r0 = load i32* @a, align 4
  %r1 = load i32* @b, align 4
  %call2 = call i32 @gcd(i32 %r0, i32 %r1)
  %call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %call2)
  %call4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  %r2 = alloca i32, align 4
  store i32 0, i32* %r2
  %r3 = load i32* %r2
  ret i32 %r3
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
