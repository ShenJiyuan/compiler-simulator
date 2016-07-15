@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

define i32 @main() #0
{
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %a)
  %call1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %b)
  %r0 = load i32* %a, align 4
  %r1 = load i32* %b, align 4
  %r2 = add nsw i32 %r0, %r1
  %call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %r2)
  %call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  %r3 = alloca i32, align 4
  store i32 0, i32* %r3
  %r4 = load i32* %r3
  ret i32 %r4
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
