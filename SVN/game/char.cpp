// find

}

void CHARACTER::Create(con

// add above

#ifdef ENABLE_CLICK_WON
	m_dwLastWonTime = 0;
#endif

//add

#ifdef ENABLE_CLICK_WON 
void CHARACTER::ClickWonExchange(const bool IsWon)
{
	if (IsDead() || IsStun() || IsHack(true))
		return;

	if (thecore_pulse() - GetLastClickWonTime() < passes_per_sec * 1)
	{
		ChatPacket(1, "Please wait 1 sec");
		return;
	}

	constexpr DWORD needYang = 1'000'000'000;
	if (IsWon)
	{
		if (GetGold() < needYang)
		{
			ChatPacket(1, "You need %d yang", needYang);
			return;
		}
		if (GetCheque() >= CHEQUE_MAX)
		{
			ChatPacket(1,"You have already max won");
			return;
		}
		PointChange(POINT_CHEQUE, 1, false);
		PointChange(POINT_GOLD, -needYang, false);
		ChatPacket(1, "transfer successful");
	}
	else
	{
		if (GetCheque() <= 0)
		{
			ChatPacket(1,"You need '1' won");
			return;
		}
		if (GetGold() + needYang > GOLD_MAX - 1'000'000)
		{
			ChatPacket(1,"You have already max yang");
			return;
		}
		PointChange(POINT_GOLD, needYang, false);
		PointChange(POINT_CHEQUE, -1, false);
		ChatPacket(1, "transfer successful");
	}
	SetLastClickWonTime(thecore_pulse());
}
#endif