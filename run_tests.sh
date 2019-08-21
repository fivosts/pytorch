#/bin/bash

./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=MakeIntrusiveTest.ClassWith0Parameters  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace1.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=MakeIntrusiveTest.ClassWith1Parameters  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace2.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=MakeIntrusiveTest.ClassWith2Parameters  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace3.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=MakeIntrusiveTest.TypeIsAutoDeductible  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace4.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=MakeIntrusiveTest.CanAssignToBaseClassPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace5.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTargetTest.whenAllocatedOnStack_thenDoesntCrash  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace6.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCallingGet_thenReturnsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace7.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCallingConstGet_thenReturnsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace8.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenCallingGet_thenReturnsNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace9.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenDereferencing_thenReturnsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace10.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenConstDereferencing_thenReturnsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace11.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenArrowDereferencing_thenReturnsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace12.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenConstArrowDereferencing_thenReturnsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace13.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace14.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigning_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace15.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigningToSelf_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace16.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigningToSelf_thenStaysValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace17.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenMoveAssigningToSelf_thenStaysInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace18.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenMoveAssigning_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace19.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenMoveAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace20.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigningFromInvalidPtr_thenNewInstanceIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace21.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace22.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenMoveAssigningToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace23.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenMoveAssigningToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace24.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace25.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenMoveAssigningInvalidPtrToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace26.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenNullPtr_whenMoveAssigningToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace27.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCopyAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace28.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCopyAssigning_thenOldInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace29.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCopyAssigningToSelf_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace30.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCopyAssigningToSelf_thenStaysValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace31.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenCopyAssigningToSelf_thenStaysInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace32.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenCopyAssigning_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace33.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace34.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenValidPtr_whenCopyAssigningToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace35.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenCopyAssigningToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace36.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenInvalidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace37.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssigningInvalidPtrToBaseClass_thenNewInstanceIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace38.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenNullPtr_whenCopyAssigningToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace39.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructing_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace40.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructing_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace41.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructing_thenNewInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace42.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructingFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace43.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace44.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace45.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClass_thenNewInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace46.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace47.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenNullPtr_whenMoveConstructingToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace48.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructing_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace49.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructing_thenOldInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace50.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructing_thenNewInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace51.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructingFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace52.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace53.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace54.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClass_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace55.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace56.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenNullPtr_whenCopyConstructingToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace57.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapFunction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace58.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapMethod  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace59.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapFunctionFromInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace60.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapMethodFromInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace61.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapFunctionWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace62.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapMethodWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace63.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapFunctionInvalidWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace64.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.SwapMethodInvalidWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace65.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.CanBePutInContainer  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace66.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.CanBePutInSet  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace67.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.CanBePutInUnorderedSet  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace68.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.CanBePutInMap  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace69.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.CanBePutInUnorderedMap  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace70.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.Equality_AfterCopyConstructor  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace71.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.Equality_AfterCopyAssignment  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace72.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.Equality_Nullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace73.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.Nonequality  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace74.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.Nonequality_NullptrLeft  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace75.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.Nonequality_NullptrRight  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace76.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.HashIsDifferent  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace77.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.HashIsDifferent_ValidAndInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace78.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.HashIsSame_AfterCopyConstructor  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace79.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.HashIsSame_AfterCopyAssignment  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace80.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.HashIsSame_BothNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace81.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.OneIsLess  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace82.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.NullptrIsLess1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace83.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.NullptrIsLess2  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace84.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.NullptrIsNotLessThanNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace85.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCallingReset_thenIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace86.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCallingReset_thenHoldsNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace87.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenDestructed_thenDestructsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace88.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructed_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace89.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveConstructedToBaseClass_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace90.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveAssigned_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace91.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveAssignedToBaseClass_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace92.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace93.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithBaseClassCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace94.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithCopy_whenMoveAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace95.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveAssigned_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace96.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenMoveAssignedToBaseClass_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace97.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructedAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace98.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace99.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace100.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyConstructedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace101.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssignedAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace102.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssignedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace103.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssignedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace104.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssignedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace105.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssigned_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace106.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCopyAssignedToBaseClass_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace107.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace108.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithBaseClassCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace109.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithCopy_whenCopyAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace110.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenCallingReset_thenDestructs  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace111.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithCopy_whenCallingReset_thenDestructsAfterCopyDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace112.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithCopy_whenCallingResetOnCopy_thenDestructsAfterOriginalDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace113.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithMoved_whenCallingReset_thenDestructsAfterMovedDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace114.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtrWithMoved_whenCallingResetOnMoved_thenDestructsImmediately  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace115.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.AllowsMoveConstructingToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace116.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.AllowsCopyConstructingToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace117.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.AllowsMoveAssigningToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace118.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.AllowsCopyAssigningToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace119.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenNewPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace120.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenNewPtr_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace121.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenEmptyPtr_thenHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace122.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenEmptyPtr_thenIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace123.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenResetPtr_thenHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace124.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenResetPtr_thenIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace125.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveConstructedPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace126.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveConstructedPtr_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace127.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveConstructedPtr_thenOldHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace128.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveConstructedPtr_thenOldIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace129.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveAssignedPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace130.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveAssignedPtr_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace131.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveAssignedPtr_thenOldHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace132.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenMoveAssignedPtr_thenOldIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace133.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_thenHasUseCount2  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace134.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_thenIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace135.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_thenOldHasUseCount2  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace136.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_thenOldIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace137.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_whenDestructingCopy_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace138.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_whenDestructingCopy_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace139.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_whenReassigningCopy_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace140.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyConstructedPtr_whenReassigningCopy_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace141.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyAssignedPtr_thenHasUseCount2  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace142.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyAssignedPtr_thenIsNotUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace143.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyAssignedPtr_whenDestructingCopy_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace144.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyAssignedPtr_whenDestructingCopy_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace145.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyAssignedPtr_whenReassigningCopy_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace146.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenCopyAssignedPtr_whenReassigningCopy_thenIsUnique  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace147.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenReleasedAndReclaimed_thenDoesntCrash  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace148.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenReleasedAndReclaimed_thenIsDestructedAtEnd  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace149.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenStackObject_whenReclaimed_thenCrashes  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace150.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenNonOwningReclaimed_thenDoesntCrash  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace151.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=IntrusivePtrTest.givenPtr_whenNonOwningReclaimed_thenIsDestructedAtEnd  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace152.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCreatingAndDestructing_thenDoesntCrash  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace153.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenLocking_thenReturnsCorrectObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace154.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace155.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigning_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace156.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenMoveAssigning_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace157.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigningToSelf_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace158.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigningToSelf_thenStaysValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace159.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenMoveAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace160.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenMoveAssigningToSelf_thenStaysInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace161.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigning_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace162.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace163.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigningToSelf_thenStaysInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace164.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigningToSelf_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace165.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigningFromInvalidPtr_thenNewInstanceIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace166.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigningFromWeakOnlyPtr_thenNewInstanceIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace167.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace168.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenMoveAssigningToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace169.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenMoveAssigningToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace170.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace171.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenMoveAssigningInvalidPtrToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace172.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigningToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace173.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace174.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenMoveAssigningInvalidPtrToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace175.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenNullPtr_whenMoveAssigningToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace176.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenCopyAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace177.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenCopyAssigning_thenOldInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace178.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenCopyAssigningToSelf_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace179.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenCopyAssigningToSelf_thenStaysValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace180.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenCopyAssigning_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace181.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenCopyAssigningToSelf_thenStaysInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace182.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenCopyAssigning_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace183.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenCopyAssigning_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace184.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenCopyAssigningToSelf_thenStaysInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace185.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenCopyAssigningToSelf_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace186.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace187.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenValidPtr_whenCopyAssigningToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace188.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenCopyAssigningToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace189.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace190.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssigningInvalidPtrToBaseClass_thenNewInstanceIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace191.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenCopyAssigningToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace192.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace193.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssigningWeakOnlyPtrToBaseClass_thenNewInstanceIsValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace194.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenNullPtr_whenCopyAssigningToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace195.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructing_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace196.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructing_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace197.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructing_thenNewInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace198.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace199.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingFromWeakOnlyPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace200.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace201.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace202.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClass_thenNewInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace203.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace204.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructingToBaseClassFromWeakOnlyPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace205.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenNullPtr_whenMoveConstructingToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace206.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructing_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace207.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructing_thenOldInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace208.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructing_thenNewInstanceValid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace209.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace210.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingFromWeakOnlyPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace211.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClass_thenPointsToSameObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace212.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClass_thenOldInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace213.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClass_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace214.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace215.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructingToBaseClassFromWeakOnlyPtr_thenNewInstanceInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace216.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenNullPtr_whenCopyConstructingToDifferentNullptr_thenHasNewNullptr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace217.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace218.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethod  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace219.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunctionFromInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace220.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethodFromInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace221.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunctionWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace222.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethodWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace223.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunctionInvalidWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace224.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethodInvalidWithInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace225.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunctionFromWeakOnlyPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace226.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethodFromWeakOnlyPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace227.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunctionWithWeakOnlyPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace228.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethodWithWeakOnlyPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace229.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapFunctionWeakOnlyPtrWithWeakOnlyPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace230.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.SwapMethodWeakOnlyPtrWithWeakOnlyPtr  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace231.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.CanBePutInContainer  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace232.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.CanBePutInSet  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace233.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.CanBePutInUnorderedSet  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace234.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.CanBePutInMap  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace235.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.CanBePutInUnorderedMap  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace236.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Equality_AfterCopyConstructor  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace237.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Equality_AfterCopyAssignment  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace238.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Equality_AfterCopyAssignment_WeakOnly  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace239.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Equality_Invalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace240.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Nonequality  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace241.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Nonequality_InvalidLeft  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace242.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Nonequality_InvalidRight  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace243.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.Nonequality_WeakOnly  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace244.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsDifferent  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace245.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsDifferent_ValidAndInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace246.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsDifferent_ValidAndWeakOnly  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace247.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsDifferent_WeakOnlyAndWeakOnly  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace248.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsSame_AfterCopyConstructor  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace249.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsSame_AfterCopyConstructor_WeakOnly  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace250.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsSame_AfterCopyAssignment  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace251.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsSame_AfterCopyAssignment_WeakOnly  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace252.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.HashIsSame_BothInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace253.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.OneIsLess  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace254.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.InvalidIsLess1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace255.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.InvalidIsLess2  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace256.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.InvalidIsNotLessThanInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace257.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingResetOnWeakPtr_thenIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace258.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingResetOnStrongPtr_thenIsInvalid  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace259.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.AllowsMoveConstructingToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace260.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.AllowsCopyConstructingToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace261.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.AllowsMoveAssigningToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace262.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.AllowsCopyAssigningToConst  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace263.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenNewPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace264.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenNewPtr_thenIsNotExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace265.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_thenHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace266.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenInvalidPtr_thenIsExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace267.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_thenHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace268.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_thenIsExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace269.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingWeakReset_thenHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace270.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingWeakReset_thenIsExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace271.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingStrongReset_thenHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace272.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingStrongReset_thenIsExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace273.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveConstructedPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace274.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveConstructedPtr_thenIsNotExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace275.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveConstructedPtr_thenOldHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace276.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveConstructedPtr_thenOldIsExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace277.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveAssignedPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace278.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveAssignedPtr_thenIsNotExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace279.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveAssignedPtr_thenOldHasUseCount0  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace280.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenMoveAssignedPtr_thenOldIsExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace281.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenCopyConstructedPtr_thenHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace282.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenCopyConstructedPtr_thenIsNotExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace283.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenCopyConstructedPtr_thenOldHasUseCount1  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace284.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenCopyConstructedPtr_thenOldIsNotExpired  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace285.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenLastStrongPointerResets_thenReleasesResources  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace286.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenDestructedButStillHasStrongPointers_thenDoesntReleaseResources  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace287.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenDestructed_thenDestructsObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace288.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructed_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace289.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveConstructedToBaseClass_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace290.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveAssigned_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace291.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveAssignedToBaseClass_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace292.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace293.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithBaseClassCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace294.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithCopy_whenMoveAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace295.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveAssigned_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace296.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenMoveAssignedToBaseClass_thenDestructsObjectAfterSecondDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace297.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructedAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace298.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace299.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace300.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyConstructedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace301.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssignedAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace302.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssignedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace303.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssignedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace304.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssignedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace305.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssigned_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace306.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCopyAssignedToBaseClass_thenDestructsOldObject  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace307.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace308.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithBaseClassCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace309.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithCopy_whenCopyAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace310.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenCallingReset_thenDestructs  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace311.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithCopy_whenCallingReset_thenDestructsAfterCopyDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace312.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithCopy_whenCallingResetOnCopy_thenDestructsAfterOriginalDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace313.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithMoved_whenCallingReset_thenDestructsAfterMovedDestructed  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace314.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtrWithMoved_whenCallingResetOnMoved_thenDestructsImmediately  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace315.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenReleasedAndReclaimed_thenDoesntCrash  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace316.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenReleasedAndReclaimed_thenDoesntCrash  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace317.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenPtr_whenReleasedAndReclaimed_thenIsDestructedAtEnd  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace318.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenWeakOnlyPtr_whenReleasedAndReclaimed_thenIsDestructedAtEnd  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace319.log
echo "------------------"
echo ""
./build/bin/opt-c10_intrusive_ptr_test --gtest_filter=WeakIntrusivePtrTest.givenStackObject_whenReclaimed_thenCrashes  #> /home/fivosts/trace_classification/Pytorch/fail/traces/trace320.log
echo "------------------"
echo ""
