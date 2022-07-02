Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=59", ENDITEM, 
		"Name=login.y", "Value=18", ENDITEM, 
		EXTRARES, 
		"Url=https://c.urs.microsoft.com/l1.dat?v=3&cv=9.11.19041.0&os=10.0.19044.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", "Referer=", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://ieonline.microsoft.com/iedomainsuggestions/ie11/suggestions.ru-RU", "Referer=", ENDITEM, 
		LAST);

	lr_think_time(8);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=07/03/2022", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=07/04/2022", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=42", ENDITEM, 
		"Name=findFlights.y", "Value=13", ENDITEM, 
		LAST);

	lr_think_time(8);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=011;644;07/03/2022", ENDITEM, 
		"Name=returnFlight", "Value=101;644;07/04/2022", ENDITEM, 
		"Name=reserveFlights.x", "Value=44", ENDITEM, 
		"Name=reserveFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_think_time(35);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t7.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=Adress", ENDITEM, 
		"Name=address2", "Value=New York", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=1234432112344321", ENDITEM, 
		"Name=expDate", "Value=07/99", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=62", ENDITEM, 
		"Name=buyFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(15);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}