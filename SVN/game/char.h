// add

#ifdef ENABLE_CLICK_WON
	private:
		DWORD m_dwLastWonTime;
	public:
		void			ClickWonExchange(bool IsWon);
		DWORD			GetLastClickWonTime() const { return m_dwLastWonTime; }
		void			SetLastClickWonTime(DWORD time) {m_dwLastWonTime = time; }
#endif