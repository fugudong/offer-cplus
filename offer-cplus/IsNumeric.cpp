bool isNumeric(char* string)
{
	if (string == nullptr)
		return false;
	if (*string == '\0')
		return false;
	if (*string == '+' || *string == '-')
		string++;
	int hasNum = 0, hasExp = 0, hasDot = 0;
	while (*string != '\0') {
		if (*string >= '0' && *string <= '9') {
			string++;
			hasNum = 1;
		}
		else if (*string == '.') {
			if (hasDot || hasExp) {
				return 0;
			}
			hasDot = 1;
			string++;
		}
		else if (*string == 'e' || *string == 'E') {
			hasExp = 1;
			if (hasNum == 0)
				return false;
			if (hasDot && hasNum == 0)
				return false;
			string++;
			if (*string == '+' || *string == '-')
				string++;
			if (*string == '\0')
				return false;
		}
		else
			return false;

	}
	return true;
}