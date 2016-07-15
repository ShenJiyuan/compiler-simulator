; ModuleID = 'struct.c'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

%struct.doubleO = type { i32, i32, i32, i32, i32 }
%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld = type { i32 }
%struct.haoehaoehaoewozhendehaoe = type { i32, i32, i32, i32 }

@T = common global %struct.doubleO zeroinitializer, align 4
@A = common global %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4
@C = common global %struct.haoehaoehaoewozhendehaoe zeroinitializer, align 4
@G = common global %struct.doubleO zeroinitializer, align 4
@R = common global %struct.doubleO zeroinitializer, align 4
@B = common global %struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld zeroinitializer, align 4

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1
  %2 = load i32* getelementptr inbounds (%struct.doubleO* @T, i32 0, i32 0), align 4
  %3 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %2)
  %4 = load i32* getelementptr inbounds (%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld* @A, i32 0, i32 0), align 4
  %5 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %4)
  %6 = load i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 1), align 4
  %7 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %6)
  %8 = load i32* getelementptr inbounds (%struct.doubleO* @T, i32 0, i32 0), align 4
  %9 = load i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 1), align 4
  %10 = xor i32 %8, %9
  store i32 %10, i32* getelementptr inbounds (%struct.doubleO* @G, i32 0, i32 1), align 4
  %11 = load i32* getelementptr inbounds (%struct.doubleO* @G, i32 0, i32 1), align 4
  %12 = load i32* getelementptr inbounds (%struct.acrossthegreatxxxxwallwecanreacheverycornerintheworld* @A, i32 0, i32 0), align 4
  %13 = icmp eq i32 %11, %12
  br i1 %13, label %14, label %15

; <label>:14                                      ; preds = %0
  store i32 215, i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0), align 4
  br label %16

; <label>:15                                      ; preds = %0
  store i32 0, i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0), align 4
  br label %16

; <label>:16                                      ; preds = %15, %14
  %17 = load i32* getelementptr inbounds (%struct.haoehaoehaoewozhendehaoe* @C, i32 0, i32 0), align 4
  %18 = call i32 bitcast (i32 (...)* @write to i32 (i32)*)(i32 %17)
  %19 = load i32* getelementptr inbounds (%struct.doubleO* @R, i32 0, i32 2), align 4
  %20 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %19)
  %21 = load i32* getelementptr inbounds (%struct.doubleO* @R, i32 0, i32 2), align 4
  %22 = icmp ne i32 %21, 0
  br i1 %22, label %23, label %25

; <label>:23                                      ; preds = %16
  %24 = call i32 bitcast (i32 (...)* @write to i32 (i32)*)(i32 215)
  br label %27

; <label>:25                                      ; preds = %16
  %26 = call i32 bitcast (i32 (...)* @write to i32 (i32)*)(i32 -215)
  br label %27

; <label>:27                                      ; preds = %25, %23
  ret i32 0
}

declare i32 @read(...) #1

declare i32 @write(...) #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
