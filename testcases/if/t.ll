@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

define i32 @main() #0
{
entry:
  %r0 = icmp eq i32 1, 2
  br i1 %r0, label %if0.then, label %if0.else

if0.then:
  %call0 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 345)
  %call1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  br label %if0.end

if0.else:
  %call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 678)
  %call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  br label %if0.end

if0.end:
  %r1 = alloca i32, align 4
  store i32 0, i32* %r1
  %r2 = load i32* %r1
  ret i32 %r2
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
