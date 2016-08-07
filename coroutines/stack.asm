declare i8* @llvm.stacksave()
declare void @llvm.stackrestore(i8*)


define i8* @save_stack() {

  %ptr = call i8* @llvm.stacksave()
  ret i8* %ptr
}


define void @stack_restor(i8* %ptr) {

  call void @llvm.stackrestore(i8* %ptr)
  ret void
}
