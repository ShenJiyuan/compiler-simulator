; ModuleID = 'fib.c'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@mat = global [4 x i32] [i32 0, i32 1, i32 1, i32 1], align 4
@MOD = global i32 10007, align 4
@solve.ans = private unnamed_addr constant [2 x i32] [i32 0, i32 1], align 4
@n = common global i32 0, align 4

; Function Attrs: nounwind
define i32 @solve(i32 %x) #0 {
  %1 = alloca i32, align 4
  %p = alloca i32, align 4
  %q = alloca i32, align 4
  %r = alloca i32, align 4
  %s = alloca i32, align 4
  %ans = alloca [2 x i32], align 4
  store i32 %x, i32* %1, align 4
  %2 = bitcast [2 x i32]* %ans to i8*
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %2, i8* bitcast ([2 x i32]* @solve.ans to i8*), i32 8, i32 4, i1 false)
  br label %3

; <label>:3                                       ; preds = %78, %0
  %4 = load i32* %1, align 4
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %81

; <label>:6                                       ; preds = %3
  %7 = load i32* %1, align 4
  %8 = and i32 %7, 1
  %9 = icmp ne i32 %8, 0
  br i1 %9, label %10, label %37

; <label>:10                                      ; preds = %6
  %11 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  %12 = load i32* %11, align 4
  %13 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 0), align 4
  %14 = mul nsw i32 %12, %13
  %15 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  %16 = load i32* %15, align 4
  %17 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 2), align 4
  %18 = mul nsw i32 %16, %17
  %19 = add nsw i32 %14, %18
  store i32 %19, i32* %p, align 4
  %20 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  %21 = load i32* %20, align 4
  %22 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 1), align 4
  %23 = mul nsw i32 %21, %22
  %24 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  %25 = load i32* %24, align 4
  %26 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 3), align 4
  %27 = mul nsw i32 %25, %26
  %28 = add nsw i32 %23, %27
  store i32 %28, i32* %q, align 4
  %29 = load i32* %p, align 4
  %30 = load i32* @MOD, align 4
  %31 = srem i32 %29, %30
  %32 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  store i32 %31, i32* %32, align 4
  %33 = load i32* %q, align 4
  %34 = load i32* @MOD, align 4
  %35 = srem i32 %33, %34
  %36 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 1
  store i32 %35, i32* %36, align 4
  br label %37

; <label>:37                                      ; preds = %10, %6
  %38 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 0), align 4
  %39 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 0), align 4
  %40 = mul nsw i32 %38, %39
  %41 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 1), align 4
  %42 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 2), align 4
  %43 = mul nsw i32 %41, %42
  %44 = add nsw i32 %40, %43
  store i32 %44, i32* %p, align 4
  %45 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 0), align 4
  %46 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 1), align 4
  %47 = mul nsw i32 %45, %46
  %48 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 1), align 4
  %49 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 3), align 4
  %50 = mul nsw i32 %48, %49
  %51 = add nsw i32 %47, %50
  store i32 %51, i32* %q, align 4
  %52 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 2), align 4
  %53 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 0), align 4
  %54 = mul nsw i32 %52, %53
  %55 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 3), align 4
  %56 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 2), align 4
  %57 = mul nsw i32 %55, %56
  %58 = add nsw i32 %54, %57
  store i32 %58, i32* %r, align 4
  %59 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 1), align 4
  %60 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 2), align 4
  %61 = mul nsw i32 %59, %60
  %62 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 3), align 4
  %63 = load i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 3), align 4
  %64 = mul nsw i32 %62, %63
  %65 = add nsw i32 %61, %64
  store i32 %65, i32* %s, align 4
  %66 = load i32* %p, align 4
  %67 = load i32* @MOD, align 4
  %68 = srem i32 %66, %67
  store i32 %68, i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 0), align 4
  %69 = load i32* %q, align 4
  %70 = load i32* @MOD, align 4
  %71 = srem i32 %69, %70
  store i32 %71, i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 1), align 4
  %72 = load i32* %r, align 4
  %73 = load i32* @MOD, align 4
  %74 = srem i32 %72, %73
  store i32 %74, i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 2), align 4
  %75 = load i32* %s, align 4
  %76 = load i32* @MOD, align 4
  %77 = srem i32 %75, %76
  store i32 %77, i32* getelementptr inbounds ([4 x i32]* @mat, i32 0, i32 3), align 4
  br label %78

; <label>:78                                      ; preds = %37
  %79 = load i32* %1, align 4
  %80 = ashr i32 %79, 1
  store i32 %80, i32* %1, align 4
  br label %3

; <label>:81                                      ; preds = %3
  %82 = getelementptr inbounds [2 x i32]* %ans, i32 0, i32 0
  %83 = load i32* %82, align 4
  ret i32 %83
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1) #1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1
  %2 = load i32* @n, align 4
  %3 = call i32 bitcast (i32 (...)* @read to i32 (i32)*)(i32 %2)
  %4 = load i32* @n, align 4
  %5 = call i32 @solve(i32 %4)
  %6 = call i32 bitcast (i32 (...)* @write to i32 (i32)*)(i32 %5)
  ret i32 0
}

declare i32 @read(...) #2

declare i32 @write(...) #2

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
