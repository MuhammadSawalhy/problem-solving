.PHONY: compile clean stressing interaction
STRESS_FILES := main gen stress
INTERACT_FILES := main interactor

# Add check.cpp if it exists
ifneq ($(wildcard check.cpp),)
    STRESS_FILES += check
endif

ifneq ($(wildcard validate.cpp),)
    STRESS_FILES += validate
endif

stressing: $(STRESS_FILES)

interaction: $(INTERACT_FILES)

%: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(STRESS_FILES) stress-ans stress-inf stress-ouf
	rm -f $(INTERACT_FILES)

