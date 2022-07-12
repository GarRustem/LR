Action()
{
	/* HOMEPAGE */

	homepage();

	/* SIGN UP */

	lr_start_transaction("sign_up");

	web_reg_find("Text=First time registering? Please complete the form below.", 
		LAST);

	lr_think_time(20);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_save_string(lr_eval_string("{nameFirstLetter}{nameSecondLetter}{nameThirdLetter}{nameFourthLetter}"), "name");
	lr_save_string(lr_eval_string("{surenameFirstLetter}{surenameSecondLetter}{surenameThirdLetter}{surenameFourthLetter}"), "surename_and_password");
	
	web_reg_find("Text=Thank you", LAST);

	lr_think_time(69);
	
	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={name}", ENDITEM, 
		"Name=password", "Value={surename_and_password}", ENDITEM, 
		"Name=passwordConfirm", "Value={surename_and_password}", ENDITEM, 
		"Name=firstName", "Value={name}", ENDITEM, 
		"Name=lastName", "Value={surename_and_password}", ENDITEM, 
		"Name=address1", "Value={Adress}", ENDITEM, 
		"Name=address2", "Value={City}", ENDITEM, 
		"Name=register.x", "Value=63", ENDITEM, 
		"Name=register.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("sign_up",LR_AUTO);

	/* CONTINUE */

	lr_start_transaction("continue");

	web_reg_find("Text=Web Tours reservation pages", LAST);

	lr_think_time(109);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("continue",LR_AUTO);
	
	/* LOGOUT */
	
	logout();

	return 0;
}