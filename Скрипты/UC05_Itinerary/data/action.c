Action()
{

	/* ITINERARY */

	lr_think_time(80);

	lr_start_transaction("delete_go_itinerary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("delete_go_itinerary",LR_AUTO);

	/* DELETE TICKET */

	lr_think_time(68);

	lr_start_transaction("delete_chek_del_ticket");

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=0-7-JB", ENDITEM, 
		"Name=flightID", "Value=0-15-JB", ENDITEM, 
		"Name=flightID", "Value=0-23-JB", ENDITEM, 
		"Name=flightID", "Value=1-30-JB", ENDITEM, 
		"Name=flightID", "Value=0-38-JB", ENDITEM, 
		"Name=flightID", "Value=0-46-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-5462406-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-6231637-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-7000868-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-7770099-JB", ENDITEM, 
		"Name=11", "Value=on", ENDITEM, 
		"Name=flightID", "Value=292222653-8539329-JB", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=73", ENDITEM, 
		"Name=removeFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("delete_chek_del_ticket",LR_AUTO);

	/* NEW CHECK-DELETE */

	lr_think_time(43);

	lr_start_transaction("delete_check_cancel_ticket");

	web_submit_data("itinerary.pl_2", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=0-7-JB", ENDITEM, 
		"Name=flightID", "Value=0-15-JB", ENDITEM, 
		"Name=flightID", "Value=0-23-JB", ENDITEM, 
		"Name=flightID", "Value=1-30-JB", ENDITEM, 
		"Name=flightID", "Value=0-38-JB", ENDITEM, 
		"Name=flightID", "Value=0-46-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-5462406-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-6231637-JB", ENDITEM, 
		"Name=flightID", "Value=160037468-7000868-JB", ENDITEM, 
		"Name=10", "Value=on", ENDITEM, 
		"Name=flightID", "Value=160037468-7770099-JB", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=46", ENDITEM, 
		"Name=removeFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("delete_check_cancel_ticket",LR_AUTO);

	/* MULTIPLE DELETE */

	lr_think_time(33);

	lr_start_transaction("delete_multiple_delete");

	web_submit_data("itinerary.pl_3", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=0-7-JB", ENDITEM, 
		"Name=flightID", "Value=0-15-JB", ENDITEM, 
		"Name=flightID", "Value=0-23-JB", ENDITEM, 
		"Name=flightID", "Value=1-30-JB", ENDITEM, 
		"Name=5", "Value=on", ENDITEM, 
		"Name=flightID", "Value=0-38-JB", ENDITEM, 
		"Name=6", "Value=on", ENDITEM, 
		"Name=flightID", "Value=0-46-JB", ENDITEM, 
		"Name=7", "Value=on", ENDITEM, 
		"Name=flightID", "Value=160037468-5462406-JB", ENDITEM, 
		"Name=8", "Value=on", ENDITEM, 
		"Name=flightID", "Value=160037468-6231637-JB", ENDITEM, 
		"Name=9", "Value=on", ENDITEM, 
		"Name=flightID", "Value=160037468-7000868-JB", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=54", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("delete_multiple_delete",LR_AUTO);

	return 0;
}