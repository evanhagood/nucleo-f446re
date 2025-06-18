# === Toolchain ===
CC = arm-none-eabi-gcc
SIZE = arm-none-eabi-size

# === Paths ===
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build

# === Project Files ===
TARGET = $(BUILD_DIR)/main
SRCS := $(wildcard $(SRC_DIR)/*.c) startup_stm32f446xx.s
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(filter %.c,$(SRCS)))) \
        $(patsubst %.s,$(BUILD_DIR)/%.o,$(notdir $(filter %.s,$(SRCS))))

# === Flags ===
CFLAGS = -mcpu=cortex-m4 -mthumb -g -O0 -Wall -ffreestanding -I$(INC_DIR)
LDFLAGS = -Tlinker.ld -nostartfiles -Wl,--gc-sections

# === Build ELF ===
all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(SIZE) $@

# Compile C source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile ASM source file (same dir as Makefile)
$(BUILD_DIR)/%.o: %.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Make sure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# === Flash ===
flash: $(TARGET).elf
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
		-c "program $(TARGET).elf verify reset exit"

# === Clean ===
clean:
	rm -rf $(BUILD_DIR) *.elf *.bin *.hex