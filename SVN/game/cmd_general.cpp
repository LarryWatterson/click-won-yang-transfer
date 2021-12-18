#ifdef ENABLE_CLICK_WON
ACMD(do_clickwon)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	if (!*arg1) { return; }
	bool isWon = std::stoi(arg1);
	ch->ClickWonExchange(isWon);
}
#endif