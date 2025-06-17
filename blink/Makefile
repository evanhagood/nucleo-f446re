# === Toolchain ===
CC = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

# === Project Files ===
TARGET = main
SRCS = main.c startup_stm32f446xx.s
OBJS = $(patsubst %.c,%.o,$(filter %.c,$(SRCS))) \
       $(patsubst %.s,%.o,$(filter %.s,$(SRCS)))

# === Flags ===
CFLAGS = -mcpu=cortex-m4 -mthumb -g -O0 -Wall -ffreestanding
LDFLAGS = -Tlinker.ld -nostartfiles -Wl,--gc-sections

# === Build ELF ===
all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(SIZE) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

# === Flash ===
flash: $(TARGET).elf
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
		-c "program $(TARGET).elf verify reset exit"

# === Clean ===
clean:
	rm -f *.o *.elf *.bin *.hex