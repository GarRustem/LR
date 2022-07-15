Action()
{
	lr_start_transaction("UC05_Itinerary");
	
	
	/* HOMEPAGE */
	
	homepage();
	
	
	/* LOGIN */
	
	login();
	

	/* ITINERARY */

	lr_start_transaction("go_itinerary");
	
	web_reg_find("Text=scheduled flights", LAST);
	
	lr_think_time(5);
	
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
	
	
	/* LOGOUT */
	
	logout();
	
	
	lr_end_transaction("UC05_Itinerary",LR_AUTO);

	return 0;
}