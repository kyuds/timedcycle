CC := g++

FLAGS := -std=c++20

FILES := $(wildcard *.cc)
HEADERS := $(wildcard *.h)

OUT_FILE := timer

timer: $(FILES) $(HEADERS)
	$(CC) $(FLAGS) $(FILES) -o $(OUT_FILE)

clean:
	rm -rf $(OUT_FILE)
