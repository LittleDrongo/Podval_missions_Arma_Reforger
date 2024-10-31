class SunDirectionDisplayComponentClass: ScriptComponentClass
{
}

class SunDirectionDisplayComponent: ScriptComponent
{
	override void OnPostInit(IEntity owner)
	{
		// Вызывается при инициализации компонента
		SetEventMask(owner, EntityEvent.FRAME);
	}

	override void EOnFrame(IEntity owner, float timeSlice)
	{		
		
		World world = GetGame().GetWorld();
		
		
		
		//BaseWeatherManagerEntity weatherManager = BaseWeatherManagerEntity;
		// BaseWeatherManagerEntity meatherManager = BaseWeatherManagerEntity;
		
		vector sunDir;
		vector moonDir;
		float moonPhase;

		// Получаем текущее направление на солнце и луну
		weatherManager.GetCurrentSunMoonDirAndPhase(sunDir, moonDir, moonPhase);

		print(sunDir);

	}
}
