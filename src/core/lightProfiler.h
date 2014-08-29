       
       

#ifdef	darwin
#include <stdint.h>
#include <mach/mach_time.h>
#else
#include <time.h>
#endif


#include "foundation.h"





#ifndef	LightProfiler_H
#define LightProfiler_H

namespace core {


    class LightProfiler;


class LightTimer
{
private:
    LightProfiler* _Profiler;
    	uint		_Id;
    	bool		_IsOn;
	double		_AccumulatedTime;
	uint		_Calls;
	uint		_ClockResolutionFails;
	string		_Description;
	uint _Parent;
	uint _Sibling;
	uint _Child;
	clock_t		_StartTime;
public:
	LightTimer(LightProfiler* profiler=NULL);
	void setup(uint id, const string& description, uint parent )
	{
	    this->_Id = id;
	    this->_Description = description;
	    this->_Parent = parent;
	}
	uint getId() { return this->_Id; };
	bool getIsOn() { return this->_IsOn;};
	uint getCalls() { return this->_Calls;};
	string getDescription() { return this->_Description;};
	uint getParent() { return this->_Parent;};
	uint getSibling() { return this->_Sibling;};
	uint getClockResolutionFails() { return this->_ClockResolutionFails;};
	uint getChild() { return this->_Child;};
	clock_t getStartTime() { return this->_StartTime;};
	void setStartTime( const clock_t& t) { this->_StartTime = t;};


	void	start();
	void	stop();
	void	addChild(uint child);
	uint	getNumberOfCalls() { return this->_Calls;};
	double	getAccumulatedTime() { return this->_AccumulatedTime;};

};


class	LightEventCounter
{
private:
	string		_Description;
	uint		_Calls;
	uint		_Problems;
public:

	void	setDescription(string desc) { this->_Description = desc;};
	string	getDescription() { return this->_Description;};
	void	recordCallAndProblem(bool problem);
	uint	getCalls()	{return this->_Calls;};
	uint	getProblems() {return this->_Problems;};
	LightEventCounter();
	virtual ~LightEventCounter();
};



class LightProfiler
{
public:
    LightProfiler();
private:
    	vector<LightTimer>		_Timers;
	vector<LightEventCounter>	_EventCounters;
	vector< vector<bool> >		_TimerStateStack;
	bool				_MessagesEnabled;
public:
//	LightTimer*	getTimer(int id);
//	LightTimer*	createTimer(uint parent, uint id, 
//					const string& name);
	uint	createTimer(uint parent, const string& name);
	uint	createEventCounter(string name);

	void		pushTimerStates();
	void		popTimerStates();

	void		disableMessages();

	LightTimer&	timer(uint c);
	LightEventCounter& eventCounter(uint c);

	void		dumpChildTimers(uint level, uint top);
	void		dump();


	virtual ~LightProfiler();
};


};
#endif
