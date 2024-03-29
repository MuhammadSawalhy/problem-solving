.PHONY: compile clean stressing interaction
CPPFLAGS       := $(CPPFLAGS) -DSAWALHY
STRESS_FILES   := main stress gen
INTERACT_FILES := main interactor

stressing: $(STRESS_FILES)

interaction: $(INTERACT_FILES)

%: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm $(STRESS_FILES) stress-ans stress-inf stress-ouf
	rm $(INTERACT_FILES)
