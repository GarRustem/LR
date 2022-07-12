Action()
{
	int i = 0;
	
	int random = 0;

	lr_start_transaction("UC02_DeleteTicket");
	
	/* HOMEPAGE */
	
	homepage();
	
	/* LOGIN */
	
	login();

	/* ITINERARY */

	lr_think_time(80);

	lr_start_transaction("go_itinerary");
	
	web_reg_save_param_ex("ParamName=flightCounter","LB=A total of ","RB= scheduled flights.","Ordinal=All",LAST); // параметризация количества текущих билетов.
	
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

	lr_think_time(43);
	
	lr_start_transaction("delete_ticket(s)");
	
	
	
	
	
	//i = atoi(lr_eval_string("flightCounter_1"));
	
	//random = rand() % 1 + i;
	
	//lr_save_string(lr_eval_string("{random}"), "x");
	
	
	
	
	
//	lr_output_message("Value for flightCounter is %s ", lr_eval_string("{flightCounter_1}")); // Здесь пытался понять что помещается в переменные, отрабатывает нормально только эта строка
//	lr_output_message("Value for i is %s ", lr_eval_string("i"));
//	lr_output_message("Value for random is %s ", lr_eval_string("random"));
//	lr_output_message("Value for X is %s ", lr_eval_string("{x}"));
	
	
	

	web_submit_form("itinerary.pl", 
		"Snapshot=t30.inf", 
		ITEMDATA, 
		//"Name={x}", "Value=on", ENDITEM, //Здесь должна была отрабатывать случайная переменная из диапазона от 1 до {flightCounter_1} + 1 - заменил на заранее прописанный диапазон.
		"Name={flightNum}", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=58", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("delete_ticket(s)",LR_AUTO);
	
	lr_end_transaction("UC02_DeleteTicket",LR_AUTO);

	return 0;
}