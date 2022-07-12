Action()
{

	web_reg_find("Text=Welcome to the Web Tours site.", 
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	/* HOMEPAGE */

	lr_start_transaction("homepage");

	lr_end_transaction("homepage",LR_AUTO);

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

	web_reg_find("Text=Thank you, <b>qer</b>, for registering and welcome to the Web Tours family.", 
		LAST);

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
		"Name=username", "Value=qer", ENDITEM, 
		"Name=password", "Value=qer", ENDITEM, 
		"Name=passwordConfirm", "Value=qer", ENDITEM, 
		"Name=firstName", "Value=qer", ENDITEM, 
		"Name=lastName", "Value=qer", ENDITEM, 
		"Name=address1", "Value=adress", ENDITEM, 
		"Name=address2", "Value=city", ENDITEM, 
		"Name=register.x", "Value=63", ENDITEM, 
		"Name=register.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("sign_up",LR_AUTO);

	/* CONTINUE */

	lr_start_transaction("continue");

	web_reg_find("Text=Welcome, <b>qer</b>, to the Web Tours reservation pages.", 
		LAST);

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

	return 0;
}