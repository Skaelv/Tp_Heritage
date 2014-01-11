################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AjouterCercleCommand.cpp \
../AjouterLigneCommand.cpp \
../AjouterObjetAgregeCommand.cpp \
../AjouterPolyligneCommand.cpp \
../AjouterRectangleCommand.cpp \
../Cercle.cpp \
../ClearCommand.cpp \
../Command.cpp \
../Controller.cpp \
../DeleteCommand.cpp \
../EltGeo.cpp \
../Ligne.cpp \
../Modele.cpp \
../ObjetAgrege.cpp \
../Point.cpp \
../Polyligne.cpp \
../Rectangle.cpp \
../TranslaterCommand.cpp \
../main.cpp 

OBJS += \
./AjouterCercleCommand.o \
./AjouterLigneCommand.o \
./AjouterObjetAgregeCommand.o \
./AjouterPolyligneCommand.o \
./AjouterRectangleCommand.o \
./Cercle.o \
./ClearCommand.o \
./Command.o \
./Controller.o \
./DeleteCommand.o \
./EltGeo.o \
./Ligne.o \
./Modele.o \
./ObjetAgrege.o \
./Point.o \
./Polyligne.o \
./Rectangle.o \
./TranslaterCommand.o \
./main.o 

CPP_DEPS += \
./AjouterCercleCommand.d \
./AjouterLigneCommand.d \
./AjouterObjetAgregeCommand.d \
./AjouterPolyligneCommand.d \
./AjouterRectangleCommand.d \
./Cercle.d \
./ClearCommand.d \
./Command.d \
./Controller.d \
./DeleteCommand.d \
./EltGeo.d \
./Ligne.d \
./Modele.d \
./ObjetAgrege.d \
./Point.d \
./Polyligne.d \
./Rectangle.d \
./TranslaterCommand.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


