Action()
{
	lr_start_transaction("UC01_BuyTicket");
	
	
	/* HOMEPAGE */
	
	homepage();
	
	
	/* LOGIN */
	
	login();
	

	/* FLIGHTS */

	lr_start_transaction("buy_ticket_flights");
	
	web_reg_find("Text=Flight Selections", LAST);
	
	lr_think_time(5);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("buy_ticket_flights",LR_AUTO);
	

	/* FIND FLIGHT */

	lr_start_transaction("buy_ticket_find_flight");
	
	web_reg_find("Text=Flight Selections", LAST);
	
	lr_think_time(5);

/*Correlation comment - Do not change!  Original value='011;644;07/04/2022' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

/*Correlation comment - Do not change!  Original value='101;644;07/05/2022' Name ='returnFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=returnFlight",
		"TagName=input",
		"Extract=value",
		"Name=returnFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={city}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={city}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=on", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=31", ENDITEM,
		"Name=findFlights.y", "Value=8", ENDITEM,
		LAST);

	lr_end_transaction("buy_ticket_find_flight",LR_AUTO);
	

	/* SELECT FLIGHT */

	lr_start_transaction("buy_ticket_select_flight");
	
	web_reg_find("Text=Flight Reservation", LAST);
	
	lr_think_time(5);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=38", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("buy_ticket_select_flight",LR_AUTO);
	

	/* PAYMENT DETAILS */

	lr_start_transaction("buy_ticket_payment_details");
	
	web_reg_find("Text=Reservation Made!", LAST);
	
	lr_think_time(5);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={homeStreet}", ENDITEM,
		"Name=address2", "Value={homeCity}", ENDITEM,
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={expDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=35", ENDITEM,
		"Name=buyFlights.y", "Value=8", ENDITEM,
		LAST);

	lr_end_transaction("buy_ticket_payment_details",LR_AUTO);
	

	/* LOGOUT */

	logout();
	
	
	lr_end_transaction("UC01_BuyTicket", LR_AUTO);

	return 0;
}