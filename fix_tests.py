#!/usr/bin/env python

test_cases = ["MakeIntrusiveTest.", "IntrusivePtrTargetTest.", "IntrusivePtrTest.", "WeakIntrusivePtrTest."]

t1 = ["ClassWith0Parameters", "ClassWith1Parameters", "ClassWith2Parameters", "TypeIsAutoDeductible", "CanAssignToBaseClassPtr"]
t2 = ["whenAllocatedOnStack_thenDoesntCrash"]
t3 = ["givenValidPtr_whenCallingGet_thenReturnsObject",
		"givenValidPtr_whenCallingConstGet_thenReturnsObject",
		"givenInvalidPtr_whenCallingGet_thenReturnsNullptr",
		"givenValidPtr_whenDereferencing_thenReturnsObject",
		"givenValidPtr_whenConstDereferencing_thenReturnsObject",
		"givenValidPtr_whenArrowDereferencing_thenReturnsObject",
		"givenValidPtr_whenConstArrowDereferencing_thenReturnsObject",
		"givenValidPtr_whenMoveAssigning_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigning_thenOldInstanceInvalid",
		"givenValidPtr_whenMoveAssigningToSelf_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigningToSelf_thenStaysValid",
		"givenInvalidPtr_whenMoveAssigningToSelf_thenStaysInvalid",
		"givenInvalidPtr_whenMoveAssigning_thenNewInstanceIsValid",
		"givenInvalidPtr_whenMoveAssigning_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigningFromInvalidPtr_thenNewInstanceIsInvalid",
		"givenValidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigningToBaseClass_thenOldInstanceInvalid",
		"givenInvalidPtr_whenMoveAssigningToBaseClass_thenNewInstanceIsValid",
		"givenInvalidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject",
		"givenInvalidPtr_whenMoveAssigningInvalidPtrToBaseClass_thenNewInstanceIsValid",
		"givenNullPtr_whenMoveAssigningToDifferentNullptr_thenHasNewNullptr",
		"givenValidPtr_whenCopyAssigning_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigning_thenOldInstanceValid",
		"givenValidPtr_whenCopyAssigningToSelf_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigningToSelf_thenStaysValid",
		"givenInvalidPtr_whenCopyAssigningToSelf_thenStaysInvalid",
		"givenInvalidPtr_whenCopyAssigning_thenNewInstanceIsValid",
		"givenValidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigningToBaseClass_thenOldInstanceInvalid",
		"givenInvalidPtr_whenCopyAssigningToBaseClass_thenNewInstanceIsValid",
		"givenInvalidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject",
		"givenPtr_whenCopyAssigningInvalidPtrToBaseClass_thenNewInstanceIsInvalid",
		"givenNullPtr_whenCopyAssigningToDifferentNullptr_thenHasNewNullptr",
		"givenPtr_whenMoveConstructing_thenPointsToSameObject",
		"givenPtr_whenMoveConstructing_thenOldInstanceInvalid",
		"givenPtr_whenMoveConstructing_thenNewInstanceValid",
		"givenPtr_whenMoveConstructingFromInvalidPtr_thenNewInstanceInvalid",
		"givenPtr_whenMoveConstructingToBaseClass_thenPointsToSameObject",
		"givenPtr_whenMoveConstructingToBaseClass_thenOldInstanceInvalid",
		"givenPtr_whenMoveConstructingToBaseClass_thenNewInstanceValid",
		"givenPtr_whenMoveConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid",
		"givenNullPtr_whenMoveConstructingToDifferentNullptr_thenHasNewNullptr",
		"givenPtr_whenCopyConstructing_thenPointsToSameObject",
		"givenPtr_whenCopyConstructing_thenOldInstanceValid",
		"givenPtr_whenCopyConstructing_thenNewInstanceValid",
		"givenPtr_whenCopyConstructingFromInvalidPtr_thenNewInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClass_thenPointsToSameObject",
		"givenPtr_whenCopyConstructingToBaseClass_thenOldInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClass_thenNewInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid",
		"givenNullPtr_whenCopyConstructingToDifferentNullptr_thenHasNewNullptr",
		"SwapFunction",
		"SwapMethod",
		"SwapFunctionFromInvalid",
		"SwapMethodFromInvalid",
		"SwapFunctionWithInvalid",
		"SwapMethodWithInvalid",
		"SwapFunctionInvalidWithInvalid",
		"SwapMethodInvalidWithInvalid",
		"CanBePutInContainer",
		"CanBePutInSet",
		"CanBePutInUnorderedSet",
		"CanBePutInMap",
		"CanBePutInUnorderedMap",
		"Equality_AfterCopyConstructor",
		"Equality_AfterCopyAssignment",
		"Equality_Nullptr",
		"Nonequality",
		"Nonequality_NullptrLeft",
		"Nonequality_NullptrRight",
		"HashIsDifferent",
		"HashIsDifferent_ValidAndInvalid",
		"HashIsSame_AfterCopyConstructor",
		"HashIsSame_AfterCopyAssignment",
		"HashIsSame_BothNullptr",
		"OneIsLess",
		"NullptrIsLess1",
		"NullptrIsLess2",
		"NullptrIsNotLessThanNullptr",
		"givenPtr_whenCallingReset_thenIsInvalid",
		"givenPtr_whenCallingReset_thenHoldsNullptr",
		"givenPtr_whenDestructed_thenDestructsObject",
		"givenPtr_whenMoveConstructed_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenMoveConstructedToBaseClass_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenMoveAssigned_thenDestructsOldObject",
		"givenPtr_whenMoveAssignedToBaseClass_thenDestructsOldObject",
		"givenPtrWithCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithBaseClassCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithCopy_whenMoveAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtr_whenMoveAssigned_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenMoveAssignedToBaseClass_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenCopyConstructedAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyConstructedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyConstructedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyConstructedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssigned_thenDestructsOldObject",
		"givenPtr_whenCopyAssignedToBaseClass_thenDestructsOldObject",
		"givenPtrWithCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithBaseClassCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithCopy_whenCopyAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtr_whenCallingReset_thenDestructs",
		"givenPtrWithCopy_whenCallingReset_thenDestructsAfterCopyDestructed",
		"givenPtrWithCopy_whenCallingResetOnCopy_thenDestructsAfterOriginalDestructed",
		"givenPtrWithMoved_whenCallingReset_thenDestructsAfterMovedDestructed",
		"givenPtrWithMoved_whenCallingResetOnMoved_thenDestructsImmediately",
		"AllowsMoveConstructingToConst",
		"AllowsCopyConstructingToConst",
		"AllowsMoveAssigningToConst",
		"AllowsCopyAssigningToConst",
		"givenNewPtr_thenHasUseCount1",
		"givenNewPtr_thenIsUnique",
		"givenEmptyPtr_thenHasUseCount0",
		"givenEmptyPtr_thenIsNotUnique",
		"givenResetPtr_thenHasUseCount0",
		"givenResetPtr_thenIsNotUnique",
		"givenMoveConstructedPtr_thenHasUseCount1",
		"givenMoveConstructedPtr_thenIsUnique",
		"givenMoveConstructedPtr_thenOldHasUseCount0",
		"givenMoveConstructedPtr_thenOldIsNotUnique",
		"givenMoveAssignedPtr_thenHasUseCount1",
		"givenMoveAssignedPtr_thenIsUnique",
		"givenMoveAssignedPtr_thenOldHasUseCount0",
		"givenMoveAssignedPtr_thenOldIsNotUnique",
		"givenCopyConstructedPtr_thenHasUseCount2",
		"givenCopyConstructedPtr_thenIsNotUnique",
		"givenCopyConstructedPtr_thenOldHasUseCount2",
		"givenCopyConstructedPtr_thenOldIsNotUnique",
		"givenCopyConstructedPtr_whenDestructingCopy_thenHasUseCount1",
		"givenCopyConstructedPtr_whenDestructingCopy_thenIsUnique",
		"givenCopyConstructedPtr_whenReassigningCopy_thenHasUseCount1",
		"givenCopyConstructedPtr_whenReassigningCopy_thenIsUnique",
		"givenCopyAssignedPtr_thenHasUseCount2",
		"givenCopyAssignedPtr_thenIsNotUnique",
		"givenCopyAssignedPtr_whenDestructingCopy_thenHasUseCount1",
		"givenCopyAssignedPtr_whenDestructingCopy_thenIsUnique",
		"givenCopyAssignedPtr_whenReassigningCopy_thenHasUseCount1",
		"givenCopyAssignedPtr_whenReassigningCopy_thenIsUnique",
		"givenPtr_whenReleasedAndReclaimed_thenDoesntCrash",
		"givenPtr_whenReleasedAndReclaimed_thenIsDestructedAtEnd",
		"givenStackObject_whenReclaimed_thenCrashes",
		"givenPtr_whenNonOwningReclaimed_thenDoesntCrash",
		"givenPtr_whenNonOwningReclaimed_thenIsDestructedAtEnd" ]

t4 = ["givenPtr_whenCreatingAndDestructing_thenDoesntCrash",
		"givenPtr_whenLocking_thenReturnsCorrectObject",
		"givenValidPtr_whenMoveAssigning_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigning_thenOldInstanceInvalid",
		"givenInvalidPtr_whenMoveAssigning_thenNewInstanceIsValid",
		"givenValidPtr_whenMoveAssigningToSelf_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigningToSelf_thenStaysValid",
		"givenInvalidPtr_whenMoveAssigning_thenPointsToSameObject",
		"givenInvalidPtr_whenMoveAssigningToSelf_thenStaysInvalid",
		"givenWeakOnlyPtr_whenMoveAssigning_thenNewInstanceIsValid",
		"givenWeakOnlyPtr_whenMoveAssigning_thenPointsToSameObject",
		"givenWeakOnlyPtr_whenMoveAssigningToSelf_thenStaysInvalid",
		"givenWeakOnlyPtr_whenMoveAssigningToSelf_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigningFromInvalidPtr_thenNewInstanceIsInvalid",
		"givenValidPtr_whenMoveAssigningFromWeakOnlyPtr_thenNewInstanceIsInvalid",
		"givenValidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject",
		"givenValidPtr_whenMoveAssigningToBaseClass_thenOldInstanceInvalid",
		"givenInvalidPtr_whenMoveAssigningToBaseClass_thenNewInstanceIsValid",
		"givenInvalidPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject",
		"givenInvalidPtr_whenMoveAssigningInvalidPtrToBaseClass_thenNewInstanceIsValid",
		"givenWeakOnlyPtr_whenMoveAssigningToBaseClass_thenNewInstanceIsValid",
		"givenWeakOnlyPtr_whenMoveAssigningToBaseClass_thenPointsToSameObject",
		"givenWeakOnlyPtr_whenMoveAssigningInvalidPtrToBaseClass_thenNewInstanceIsValid",
		"givenNullPtr_whenMoveAssigningToDifferentNullptr_thenHasNewNullptr",
		"givenValidPtr_whenCopyAssigning_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigning_thenOldInstanceValid",
		"givenValidPtr_whenCopyAssigningToSelf_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigningToSelf_thenStaysValid",
		"givenInvalidPtr_whenCopyAssigning_thenNewInstanceIsValid",
		"givenInvalidPtr_whenCopyAssigningToSelf_thenStaysInvalid",
		"givenWeakOnlyPtr_whenCopyAssigning_thenNewInstanceIsValid",
		"givenWeakOnlyPtr_whenCopyAssigning_thenPointsToSameObject",
		"givenWeakOnlyPtr_whenCopyAssigningToSelf_thenStaysInvalid",
		"givenWeakOnlyPtr_whenCopyAssigningToSelf_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject",
		"givenValidPtr_whenCopyAssigningToBaseClass_thenOldInstanceInvalid",
		"givenInvalidPtr_whenCopyAssigningToBaseClass_thenNewInstanceIsValid",
		"givenInvalidPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject",
		"givenPtr_whenCopyAssigningInvalidPtrToBaseClass_thenNewInstanceIsInvalid",
		"givenWeakOnlyPtr_whenCopyAssigningToBaseClass_thenNewInstanceIsValid",
		"givenWeakOnlyPtr_whenCopyAssigningToBaseClass_thenPointsToSameObject",
		"givenPtr_whenCopyAssigningWeakOnlyPtrToBaseClass_thenNewInstanceIsValid",
		"givenNullPtr_whenCopyAssigningToDifferentNullptr_thenHasNewNullptr",
		"givenPtr_whenMoveConstructing_thenPointsToSameObject",
		"givenPtr_whenMoveConstructing_thenOldInstanceInvalid",
		"givenPtr_whenMoveConstructing_thenNewInstanceValid",
		"givenPtr_whenMoveConstructingFromInvalidPtr_thenNewInstanceInvalid",
		"givenPtr_whenMoveConstructingFromWeakOnlyPtr_thenNewInstanceInvalid",
		"givenPtr_whenMoveConstructingToBaseClass_thenPointsToSameObject",
		"givenPtr_whenMoveConstructingToBaseClass_thenOldInstanceInvalid",
		"givenPtr_whenMoveConstructingToBaseClass_thenNewInstanceValid",
		"givenPtr_whenMoveConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid",
		"givenPtr_whenMoveConstructingToBaseClassFromWeakOnlyPtr_thenNewInstanceInvalid",
		"givenNullPtr_whenMoveConstructingToDifferentNullptr_thenHasNewNullptr",
		"givenPtr_whenCopyConstructing_thenPointsToSameObject",
		"givenPtr_whenCopyConstructing_thenOldInstanceValid",
		"givenPtr_whenCopyConstructing_thenNewInstanceValid",
		"givenPtr_whenCopyConstructingFromInvalidPtr_thenNewInstanceInvalid",
		"givenPtr_whenCopyConstructingFromWeakOnlyPtr_thenNewInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClass_thenPointsToSameObject",
		"givenPtr_whenCopyConstructingToBaseClass_thenOldInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClass_thenNewInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClassFromInvalidPtr_thenNewInstanceInvalid",
		"givenPtr_whenCopyConstructingToBaseClassFromWeakOnlyPtr_thenNewInstanceInvalid",
		"givenNullPtr_whenCopyConstructingToDifferentNullptr_thenHasNewNullptr",
		"SwapFunction",
		"SwapMethod",
		"SwapFunctionFromInvalid",
		"SwapMethodFromInvalid",
		"SwapFunctionWithInvalid",
		"SwapMethodWithInvalid",
		"SwapFunctionInvalidWithInvalid",
		"SwapMethodInvalidWithInvalid",
		"SwapFunctionFromWeakOnlyPtr",
		"SwapMethodFromWeakOnlyPtr",
		"SwapFunctionWithWeakOnlyPtr",
		"SwapMethodWithWeakOnlyPtr",
		"SwapFunctionWeakOnlyPtrWithWeakOnlyPtr",
		"SwapMethodWeakOnlyPtrWithWeakOnlyPtr",
		"CanBePutInContainer",
		"CanBePutInSet",
		"CanBePutInUnorderedSet",
		"CanBePutInMap",
		"CanBePutInUnorderedMap",
		"Equality_AfterCopyConstructor",
		"Equality_AfterCopyAssignment",
		"Equality_AfterCopyAssignment_WeakOnly",
		"Equality_Invalid",
		"Nonequality",
		"Nonequality_InvalidLeft",
		"Nonequality_InvalidRight",
		"Nonequality_WeakOnly",
		"HashIsDifferent",
		"HashIsDifferent_ValidAndInvalid",
		"HashIsDifferent_ValidAndWeakOnly",
		"HashIsDifferent_WeakOnlyAndWeakOnly",
		"HashIsSame_AfterCopyConstructor",
		"HashIsSame_AfterCopyConstructor_WeakOnly",
		"HashIsSame_AfterCopyAssignment",
		"HashIsSame_AfterCopyAssignment_WeakOnly",
		"HashIsSame_BothInvalid",
		"OneIsLess",
		"InvalidIsLess1",
		"InvalidIsLess2",
		"InvalidIsNotLessThanInvalid",
		"givenPtr_whenCallingResetOnWeakPtr_thenIsInvalid",
		"givenPtr_whenCallingResetOnStrongPtr_thenIsInvalid",
		"AllowsMoveConstructingToConst",
		"AllowsCopyConstructingToConst",
		"AllowsMoveAssigningToConst",
		"AllowsCopyAssigningToConst",
		"givenNewPtr_thenHasUseCount1",
		"givenNewPtr_thenIsNotExpired",
		"givenInvalidPtr_thenHasUseCount0",
		"givenInvalidPtr_thenIsExpired",
		"givenWeakOnlyPtr_thenHasUseCount0",
		"givenWeakOnlyPtr_thenIsExpired",
		"givenPtr_whenCallingWeakReset_thenHasUseCount0",
		"givenPtr_whenCallingWeakReset_thenIsExpired",
		"givenPtr_whenCallingStrongReset_thenHasUseCount0",
		"givenPtr_whenCallingStrongReset_thenIsExpired",
		"givenMoveConstructedPtr_thenHasUseCount1",
		"givenMoveConstructedPtr_thenIsNotExpired",
		"givenMoveConstructedPtr_thenOldHasUseCount0",
		"givenMoveConstructedPtr_thenOldIsExpired",
		"givenMoveAssignedPtr_thenHasUseCount1",
		"givenMoveAssignedPtr_thenIsNotExpired",
		"givenMoveAssignedPtr_thenOldHasUseCount0",
		"givenMoveAssignedPtr_thenOldIsExpired",
		"givenCopyConstructedPtr_thenHasUseCount1",
		"givenCopyConstructedPtr_thenIsNotExpired",
		"givenCopyConstructedPtr_thenOldHasUseCount1",
		"givenCopyConstructedPtr_thenOldIsNotExpired",
		"givenPtr_whenLastStrongPointerResets_thenReleasesResources",
		"givenPtr_whenDestructedButStillHasStrongPointers_thenDoesntReleaseResources",
		"givenPtr_whenDestructed_thenDestructsObject",
		"givenPtr_whenMoveConstructed_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenMoveConstructedToBaseClass_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenMoveAssigned_thenDestructsOldObject",
		"givenPtr_whenMoveAssignedToBaseClass_thenDestructsOldObject",
		"givenPtrWithCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithBaseClassCopy_whenMoveAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithCopy_whenMoveAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtr_whenMoveAssigned_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenMoveAssignedToBaseClass_thenDestructsObjectAfterSecondDestructed",
		"givenPtr_whenCopyConstructedAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyConstructedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyConstructedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyConstructedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedToBaseClassAndDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssignedToBaseClassAndOriginalDestructed_thenDestructsObjectAfterLastDestruction",
		"givenPtr_whenCopyAssigned_thenDestructsOldObject",
		"givenPtr_whenCopyAssignedToBaseClass_thenDestructsOldObject",
		"givenPtrWithCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithBaseClassCopy_whenCopyAssigned_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtrWithCopy_whenCopyAssignedToBaseClass_thenDestructsOldObjectAfterCopyIsDestructed",
		"givenPtr_whenCallingReset_thenDestructs",
		"givenPtrWithCopy_whenCallingReset_thenDestructsAfterCopyDestructed",
		"givenPtrWithCopy_whenCallingResetOnCopy_thenDestructsAfterOriginalDestructed",
		"givenPtrWithMoved_whenCallingReset_thenDestructsAfterMovedDestructed",
		"givenPtrWithMoved_whenCallingResetOnMoved_thenDestructsImmediately",
		"givenPtr_whenReleasedAndReclaimed_thenDoesntCrash",
		"givenWeakOnlyPtr_whenReleasedAndReclaimed_thenDoesntCrash",
		"givenPtr_whenReleasedAndReclaimed_thenIsDestructedAtEnd",
		"givenWeakOnlyPtr_whenReleasedAndReclaimed_thenIsDestructedAtEnd",
		"givenStackObject_whenReclaimed_thenCrashes" ]

tests = [t1, t2, t3, t4]

counter = 1

f = open("./run_tests.sh", 'w')
f.write("#/bin/bash\n\n")

for i, case in enumerate(test_cases):
	for test in tests[i]:
		f.write("./build/bin/{} --gtest_filter={}{}  > /home/fivosts/trace_classification/Pytorch/{}/traces/trace{}.log\necho \"------------------\"\necho \"\"\n".format("opt-c10_intrusive_ptr_test", case, test, "fail", counter))
		counter += 1
f.close()


  




