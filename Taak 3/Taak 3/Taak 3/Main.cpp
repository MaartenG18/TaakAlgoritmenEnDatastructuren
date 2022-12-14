// Maarten Gielkens
// Simon Knuts
// Yara Mijnendonckx
// iets testen
#include "MessageSender.h"

int main()
{
	MessageSender* messageSender = new MessageSender;
	messageSender->start();

	delete messageSender;
	return 0;
}