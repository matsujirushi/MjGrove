void Grove4DigitDisplay::Init()
{
	_PinClk->SetMode(HalGpio::MODE_OUTPUT);
	_PinClk->Write(true);
	_PinDio->SetMode(HalGpio::MODE_OUTPUT);
	_PinDio->Write(true);
}
