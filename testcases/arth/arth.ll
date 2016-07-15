; ModuleID = 'arth.c'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 0, i32* %1
  %2 = load i32* %a, align 4
  %3 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %2)
  %4 = load i32* %b, align 4
  %5 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %4)
  %6 = load i32* %a, align 4
  %7 = load i32* %b, align 4
  %8 = add nsw i32 %6, %7
  %9 = call i32 bitcast (i32 (...)* @write to i32 (i32)*)(i32 %8)
  ret i32 0
}

declare i32 @read(...) #1

declare i32 @write(...) #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
