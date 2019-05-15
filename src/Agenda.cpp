#include "Agenda.h"

bool Agenda::addActivity(Activity *activity)
{
	if(isOverlap(activity))
		return false;
    activities.push_back(activity);
    return true;
}

bool Agenda::isOverlap(Activity *activity)
{
    for (Activity *activity1 : activities)
    {
        if (activity1->getDay() == activity->getDay()){
        	/* se activity come�a antes de activity1, mas n�o acaba a tempo */
        	if(activity1->getStartTime() > activity->getEndTime() && activity1->getEndTime() < activity->getEndTime())
            	return true;
        	/* se activity1 come�a antes de activity, mas n�o acaba a tempo */
        	if(activity->getStartTime() > activity1->getEndTime() && activity->getEndTime() < activity1->getEndTime())
        		return true;
        }

    }
    return false;
}

