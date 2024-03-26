.PHONY: compile stress clean interact
CPPFLAGS       := $(CPPFLAGS) -DSAWALHY
STRESS_FILES   := main stress gen
INTERACT_FILES := main interactor

stress: $(STRESS_FILES)
	@bash stress.sh

interact: $(INTERACT_FILES)
	@python3 interact.py ./main ./interactor

%: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm $(STRESS_FILES) stress-ans stress-inf stress-ouf
	rm $(INTERACT_FILES)
