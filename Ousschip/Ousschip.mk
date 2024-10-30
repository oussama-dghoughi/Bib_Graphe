##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Ousschip
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/administrateur/Documents/Documents
ProjectPath            :=/home/administrateur/Documents/Documents/Ousschip
IntermediateDirectory  :=../build-$(ConfigurationName)/Ousschip
OutDir                 :=../build-$(ConfigurationName)/Ousschip
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=administrateur
Date                   :=02/02/24
CodeLitePath           :=/home/administrateur/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -lprovided -lSDL2
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)libprovided/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)libprovided/lib/debug/x64 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Ousschip/instructions.c$(ObjectSuffix) ../build-$(ConfigurationName)/Ousschip/sp.c$(ObjectSuffix) ../build-$(ConfigurationName)/Ousschip/main.c$(ObjectSuffix) ../build-$(ConfigurationName)/Ousschip/chip8.c$(ObjectSuffix) ../build-$(ConfigurationName)/Ousschip/processeur.c$(ObjectSuffix) ../build-$(ConfigurationName)/Ousschip/Ram.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Ousschip/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Ousschip"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Ousschip"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Ousschip/.d:
	@mkdir -p "../build-$(ConfigurationName)/Ousschip"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Ousschip/instructions.c$(ObjectSuffix): instructions.c ../build-$(ConfigurationName)/Ousschip/instructions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/administrateur/Documents/Documents/Ousschip/instructions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/instructions.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Ousschip/instructions.c$(DependSuffix): instructions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Ousschip/instructions.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Ousschip/instructions.c$(DependSuffix) -MM instructions.c

../build-$(ConfigurationName)/Ousschip/instructions.c$(PreprocessSuffix): instructions.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Ousschip/instructions.c$(PreprocessSuffix) instructions.c

../build-$(ConfigurationName)/Ousschip/sp.c$(ObjectSuffix): sp.c ../build-$(ConfigurationName)/Ousschip/sp.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/administrateur/Documents/Documents/Ousschip/sp.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sp.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Ousschip/sp.c$(DependSuffix): sp.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Ousschip/sp.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Ousschip/sp.c$(DependSuffix) -MM sp.c

../build-$(ConfigurationName)/Ousschip/sp.c$(PreprocessSuffix): sp.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Ousschip/sp.c$(PreprocessSuffix) sp.c

../build-$(ConfigurationName)/Ousschip/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/Ousschip/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/administrateur/Documents/Documents/Ousschip/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Ousschip/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Ousschip/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Ousschip/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/Ousschip/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Ousschip/main.c$(PreprocessSuffix) main.c

../build-$(ConfigurationName)/Ousschip/chip8.c$(ObjectSuffix): chip8.c ../build-$(ConfigurationName)/Ousschip/chip8.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/administrateur/Documents/Documents/Ousschip/chip8.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/chip8.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Ousschip/chip8.c$(DependSuffix): chip8.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Ousschip/chip8.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Ousschip/chip8.c$(DependSuffix) -MM chip8.c

../build-$(ConfigurationName)/Ousschip/chip8.c$(PreprocessSuffix): chip8.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Ousschip/chip8.c$(PreprocessSuffix) chip8.c

../build-$(ConfigurationName)/Ousschip/processeur.c$(ObjectSuffix): processeur.c ../build-$(ConfigurationName)/Ousschip/processeur.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/administrateur/Documents/Documents/Ousschip/processeur.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/processeur.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Ousschip/processeur.c$(DependSuffix): processeur.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Ousschip/processeur.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Ousschip/processeur.c$(DependSuffix) -MM processeur.c

../build-$(ConfigurationName)/Ousschip/processeur.c$(PreprocessSuffix): processeur.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Ousschip/processeur.c$(PreprocessSuffix) processeur.c

../build-$(ConfigurationName)/Ousschip/Ram.c$(ObjectSuffix): Ram.c ../build-$(ConfigurationName)/Ousschip/Ram.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/administrateur/Documents/Documents/Ousschip/Ram.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ram.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Ousschip/Ram.c$(DependSuffix): Ram.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Ousschip/Ram.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Ousschip/Ram.c$(DependSuffix) -MM Ram.c

../build-$(ConfigurationName)/Ousschip/Ram.c$(PreprocessSuffix): Ram.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Ousschip/Ram.c$(PreprocessSuffix) Ram.c


-include ../build-$(ConfigurationName)/Ousschip//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


