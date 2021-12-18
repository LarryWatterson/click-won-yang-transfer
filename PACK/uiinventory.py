# find

		## PickMoneyDialog
		dlgPickMoney = uiPickMoney.PickMoneyDialog()

# add above

		self.GetChild("Cheque_Icon").SAFE_SetMouseClickEvent(self.ClickWon, 0)
		self.GetChild("Money_Icon").SAFE_SetMouseClickEvent(self.ClickWon, 1)

# add

	def ClickWon(self, arg):
		net.SendChatPacket("/click_won %d" % (int(arg)))
