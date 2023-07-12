.PHONY: compile stress-test clean
CPPFLAGS := $(CPPFLAGS) -DSAWALHY
FILES := main generator checker

stress-test: compile
	@bash stress.sh

compile: $(FILES)

%: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm $(FILES) stress-ans stress-inf stress-ouf
