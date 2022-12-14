// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx

#include "MessageSender.h"

int main()
{
	MessageSender* messageSender = new MessageSender;
	messageSender->start();

	delete messageSender;
	return 0;
}