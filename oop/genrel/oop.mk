##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=oop
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=E:/oop
ProjectPath            :=E:/oop
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ProBook
Date                   :=8/21/2024
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="oop.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := ar rcu
CXX      := rustc
CC       := rustc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/New folder_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/moveConstructure.cpp$(ObjectSuffix) $(IntermediateDirectory)/bankingSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/constructureInitiList.cpp$(ObjectSuffix) $(IntermediateDirectory)/copyConstructre.cpp$(ObjectSuffix) $(IntermediateDirectory)/multipalInharitance.cpp$(ObjectSuffix) $(IntermediateDirectory)/functionOverrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/deepCopy.cpp$(ObjectSuffix) $(IntermediateDirectory)/encapsulation.cpp$(ObjectSuffix) $(IntermediateDirectory)/first.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/example.cpp$(ObjectSuffix) $(IntermediateDirectory)/frendFun.cpp$(ObjectSuffix) $(IntermediateDirectory)/funOverload.cpp$(ObjectSuffix) $(IntermediateDirectory)/singleInharetance.cpp$(ObjectSuffix) $(IntermediateDirectory)/New folder_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/hiraricalInharitance.cpp$(ObjectSuffix) $(IntermediateDirectory)/landrref.cpp$(ObjectSuffix) $(IntermediateDirectory)/inharetance.cpp$(ObjectSuffix) $(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix) $(IntermediateDirectory)/multiLevelInharitence.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/oop1.cpp$(ObjectSuffix) $(IntermediateDirectory)/operatorOverloading.cpp$(ObjectSuffix) $(IntermediateDirectory)/shallow.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/New folder_main.cpp$(ObjectSuffix): New folder/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/New folder/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/New folder_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/New folder_main.cpp$(PreprocessSuffix): New folder/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/New folder_main.cpp$(PreprocessSuffix) "New folder/main.cpp"

$(IntermediateDirectory)/moveConstructure.cpp$(ObjectSuffix): moveConstructure.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/moveConstructure.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/moveConstructure.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/moveConstructure.cpp$(PreprocessSuffix): moveConstructure.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/moveConstructure.cpp$(PreprocessSuffix) moveConstructure.cpp

$(IntermediateDirectory)/bankingSystem.cpp$(ObjectSuffix): bankingSystem.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/bankingSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bankingSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bankingSystem.cpp$(PreprocessSuffix): bankingSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bankingSystem.cpp$(PreprocessSuffix) bankingSystem.cpp

$(IntermediateDirectory)/constructureInitiList.cpp$(ObjectSuffix): constructureInitiList.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/constructureInitiList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/constructureInitiList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/constructureInitiList.cpp$(PreprocessSuffix): constructureInitiList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/constructureInitiList.cpp$(PreprocessSuffix) constructureInitiList.cpp

$(IntermediateDirectory)/copyConstructre.cpp$(ObjectSuffix): copyConstructre.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/copyConstructre.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/copyConstructre.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/copyConstructre.cpp$(PreprocessSuffix): copyConstructre.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/copyConstructre.cpp$(PreprocessSuffix) copyConstructre.cpp

$(IntermediateDirectory)/multipalInharitance.cpp$(ObjectSuffix): multipalInharitance.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/multipalInharitance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/multipalInharitance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/multipalInharitance.cpp$(PreprocessSuffix): multipalInharitance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/multipalInharitance.cpp$(PreprocessSuffix) multipalInharitance.cpp

$(IntermediateDirectory)/functionOverrid.cpp$(ObjectSuffix): functionOverrid.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/functionOverrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/functionOverrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/functionOverrid.cpp$(PreprocessSuffix): functionOverrid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/functionOverrid.cpp$(PreprocessSuffix) functionOverrid.cpp

$(IntermediateDirectory)/deepCopy.cpp$(ObjectSuffix): deepCopy.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/deepCopy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/deepCopy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/deepCopy.cpp$(PreprocessSuffix): deepCopy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/deepCopy.cpp$(PreprocessSuffix) deepCopy.cpp

$(IntermediateDirectory)/encapsulation.cpp$(ObjectSuffix): encapsulation.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/encapsulation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/encapsulation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/encapsulation.cpp$(PreprocessSuffix): encapsulation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/encapsulation.cpp$(PreprocessSuffix) encapsulation.cpp

$(IntermediateDirectory)/first.cpp$(ObjectSuffix): first.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/first.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/first.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/first.cpp$(PreprocessSuffix): first.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/first.cpp$(PreprocessSuffix) first.cpp

$(IntermediateDirectory)/example.cpp$(ObjectSuffix): example.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/example.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/example.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/example.cpp$(PreprocessSuffix): example.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/example.cpp$(PreprocessSuffix) example.cpp

$(IntermediateDirectory)/frendFun.cpp$(ObjectSuffix): frendFun.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/frendFun.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/frendFun.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/frendFun.cpp$(PreprocessSuffix): frendFun.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/frendFun.cpp$(PreprocessSuffix) frendFun.cpp

$(IntermediateDirectory)/funOverload.cpp$(ObjectSuffix): funOverload.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/funOverload.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/funOverload.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/funOverload.cpp$(PreprocessSuffix): funOverload.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/funOverload.cpp$(PreprocessSuffix) funOverload.cpp

$(IntermediateDirectory)/singleInharetance.cpp$(ObjectSuffix): singleInharetance.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/singleInharetance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/singleInharetance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/singleInharetance.cpp$(PreprocessSuffix): singleInharetance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/singleInharetance.cpp$(PreprocessSuffix) singleInharetance.cpp

$(IntermediateDirectory)/New folder_Account.cpp$(ObjectSuffix): New folder/Account.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/New folder/Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/New folder_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/New folder_Account.cpp$(PreprocessSuffix): New folder/Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/New folder_Account.cpp$(PreprocessSuffix) "New folder/Account.cpp"

$(IntermediateDirectory)/hiraricalInharitance.cpp$(ObjectSuffix): hiraricalInharitance.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/hiraricalInharitance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hiraricalInharitance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hiraricalInharitance.cpp$(PreprocessSuffix): hiraricalInharitance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hiraricalInharitance.cpp$(PreprocessSuffix) hiraricalInharitance.cpp

$(IntermediateDirectory)/landrref.cpp$(ObjectSuffix): landrref.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/landrref.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/landrref.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/landrref.cpp$(PreprocessSuffix): landrref.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/landrref.cpp$(PreprocessSuffix) landrref.cpp

$(IntermediateDirectory)/inharetance.cpp$(ObjectSuffix): inharetance.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/inharetance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/inharetance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/inharetance.cpp$(PreprocessSuffix): inharetance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/inharetance.cpp$(PreprocessSuffix) inharetance.cpp

$(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix): rectangle.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/rectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rectangle.cpp$(PreprocessSuffix): rectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rectangle.cpp$(PreprocessSuffix) rectangle.cpp

$(IntermediateDirectory)/multiLevelInharitence.cpp$(ObjectSuffix): multiLevelInharitence.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/multiLevelInharitence.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/multiLevelInharitence.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/multiLevelInharitence.cpp$(PreprocessSuffix): multiLevelInharitence.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/multiLevelInharitence.cpp$(PreprocessSuffix) multiLevelInharitence.cpp

$(IntermediateDirectory)/oop1.cpp$(ObjectSuffix): oop1.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/oop1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/oop1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/oop1.cpp$(PreprocessSuffix): oop1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/oop1.cpp$(PreprocessSuffix) oop1.cpp

$(IntermediateDirectory)/operatorOverloading.cpp$(ObjectSuffix): operatorOverloading.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/operatorOverloading.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/operatorOverloading.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/operatorOverloading.cpp$(PreprocessSuffix): operatorOverloading.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/operatorOverloading.cpp$(PreprocessSuffix) operatorOverloading.cpp

$(IntermediateDirectory)/shallow.cpp$(ObjectSuffix): shallow.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/oop/shallow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/shallow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/shallow.cpp$(PreprocessSuffix): shallow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/shallow.cpp$(PreprocessSuffix) shallow.cpp

##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


