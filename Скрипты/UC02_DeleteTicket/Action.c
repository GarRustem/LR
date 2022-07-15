Action()
{
	int i = 0;
	
	int random = 0;

	char * checkFlightID;


	lr_start_transaction("UC02_DeleteTicket");
	
	
	/* HOMEPAGE */
	
	homepage();
	
	
	/* LOGIN */
	
	login();
	

	/* ITINERARY */

	lr_start_transaction("go_itinerary");
	
	web_reg_find("Text=Itinerary", LAST);
	
	lr_think_time(5);
	
	web_reg_save_param_ex("ParamName=flightCounter","LB=A total of ","RB= scheduled flights.","Ordinal=All",LAST); // параметризация количества текущих билетов.
	
	web_reg_save_param_ex("ParamName=flightID","LB=value\=\"","RB=\">","Ordinal=All",LAST);
	
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("go_itinerary",LR_AUTO);
	

	/* CHECK AND DELETE TICKET(S) */
	
	lr_start_transaction("delete_ticket(s)");
	
	web_reg_find("Text=scheduled flights", LAST);
	
	lr_think_time(5);
	
	
	i = atoi(lr_eval_string("{flightCounter_1}"));
	
	random = rand() % (i + 1);
	
	lr_save_int(random, "x");
	
	lr_output_message("Value for flightCounter is %s ", lr_eval_string("{flightCounter_1}"));
	
	lr_message("i=%i", i);
	
	lr_message("random=%i", random);
	
	
	checkFlightID = lr_paramarr_idx("FlightID", random);
	

	web_submit_form("itinerary.pl", 
		"Snapshot=t30.inf", 
		ITEMDATA, 
		"Name={x}", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=58", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	
	web_reg_find("Text=checkFlightID", "Fail=Found", LAST);
	

	lr_end_transaction("delete_ticket(s)",LR_AUTO);
	
	
	/* LOGOUT */

	logout();
	
	
	lr_end_transaction("UC02_DeleteTicket",LR_AUTO);

	return 0;
}