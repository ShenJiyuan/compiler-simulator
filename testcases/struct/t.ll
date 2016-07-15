@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld = type { i32 }
%struct.haoehaoehaoewozhendehaoe = type { i32, i32, i32, i32 }
%struct.doubleO = type { i32, i32, i32, i32, i32 }
@A = common global %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@B = common global %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@C = common global %struct.haoehaoehaoewozhendehaoe zeroinitializer, align 4
@R = common global %struct.doubleO zeroinitializer, align 4
@G = common global %struct.doubleO zeroinitializer, align 4
@T = common global %struct.doubleO zeroinitializer, align 4

define i32 @main() #0
{
entry:
  %call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* getelementptr inbounds (%struct.doubleO* @T, i32 0, i32 0))
  %call1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* getelementptr inbounds (%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld* @A, i32 0, i32 0))
  %call2 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 1))
  %r0 = load i32* getelementptr inbounds (%struct.doubleO* @T, i32 0, i32 0), align 4
  %r1 = load i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 1), align 4
  %r2 = xor i32 %r0, %r1
  store i32 %r2, i32* getelementptr inbounds (%struct.doubleO* @G, i32 0, i32 1), align 4
  %r3 = load i32* getelementptr inbounds (%struct.doubleO* @G, i32 0, i32 1), align 4
  %r4 = load i32* getelementptr inbounds (%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld* @A, i32 0, i32 0), align 4
  %r5 = icmp eq i32 %r3, %r4
  br i1 %r5, label %if0.then, label %if0.else

if0.then:
  store i32 215, i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0), align 4
  br label %if0.end

if0.else:
  store i32 0, i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0), align 4
  br label %if0.end

if0.end:
  %r6 = load i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0), align 4
  %call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %r6)
  %call4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  %call5 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* getelementptr inbounds (%struct.doubleO* @R, i32 0, i32 2))
  %r7 = load i32* getelementptr inbounds (%struct.doubleO* @R, i32 0, i32 2), align 4
  %r8 = icmp ne i32 %r7, 0
  br i1 %r8, label %if1.then, label %if1.else

if1.then:
  %call6 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 215)
  %call7 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  br label %if1.end

if1.else:
  %call8 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 -215)
  %call9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))
  br label %if1.end

if1.end:
  %r9 = alloca i32, align 4
  store i32 0, i32* %r9
  %r10 = load i32* %r9
  ret i32 %r10
}

declare i32 @__isoc99_scanf(i8*, ...) #1
declare i32 @printf(i8*, ...) #1
