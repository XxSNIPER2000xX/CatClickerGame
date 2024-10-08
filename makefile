CC 		    = gcc
CFLAGS 		= -Wall -Wextra -Iutils
LDFLAGS 	= -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_DIR 	= source
HEAD_DIR	= header

OBJ_DIR		= .

SRCS 		= $(wildcard $(SRC_DIR)/*.c) #$(wildcard $(HEAD_DIR)/*.c)

OBJS		= $(SRCS:%.c = %.o)

TARGET 		= a.out

# build rule
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# compilation rule
$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -r $(wildcard $(OBJS_DIR)/*.o) $(TARGET)

print: $(SRCS)
	ls -la $?
