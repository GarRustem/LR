Action()
{
	
	lr_start_transaction("UC03_UserAuth");
	
	/* HOMEPAGE */
	
	homepage();
	
	/* LOGIN */
	
	login();

	/* LOGOUT */

	logout();
	
	lr_end_transaction("UC03_UserAuth", LR_AUTO);

	return 0;
}