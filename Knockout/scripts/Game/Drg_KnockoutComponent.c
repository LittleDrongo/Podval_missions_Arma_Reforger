class Drg_KnockoutComponentClass: ScriptComponentClass
{}

class Drg_KnockoutComponent: ScriptComponent {	
	protected SCR_ChimeraCharacter m_eCharacter;
	
	CharacterControllerComponent m_characterControllerComponent;
	
	CharacterAnimationComponent m_characterAnimationComponent;
	SCR_CharacterDamageManagerComponent m_characterDamageManagerComponent;
	ref RandomGenerator m_randomGenerator;
	
	
	
	override void OnPostInit(IEntity owner)
	{
		m_eCharacter = SCR_ChimeraCharacter.Cast(owner); //upcast
		
			
		m_characterDamageManagerComponent = SCR_CharacterDamageManagerComponent.Cast(owner.FindComponent(SCR_CharacterDamageManagerComponent));
		m_characterControllerComponent = CharacterControllerComponent.Cast(owner.FindComponent(CharacterControllerComponent));
		m_characterAnimationComponent = CharacterAnimationComponent.Cast(owner.FindComponent(CharacterAnimationComponent));
		
		m_randomGenerator = new RandomGenerator();
		
		m_characterDamageManagerComponent.GetOnDamage().Insert(OnDamage);
		
		//SetEventMask(owner, EntityEvent.FRAME);
	};
	
	override void EOnFrame(IEntity owner, float timeSlice)
	{
		vector inertiaSpeed = m_characterAnimationComponent.GetInertiaSpeed();
		PrintFormat("%1", inertiaSpeed.Length());
	}
	
	
	void OnDamage(
				  EDamageType type,
				  float damage,
				  HitZone pHitZone,
				  notnull Instigator instigator, 
				  inout vector hitTransform[3], 
				  float speed,
				  int colliderID, 
				  int nodeID)
	{
		if (type != EDamageType.KINETIC) 
			return;
		
		vector inertiaSpeed = m_characterAnimationComponent.GetInertiaSpeed();
	
		if (inertiaSpeed.Length() > 4.0)
		{	
			SetUncon();		
		} else if (m_randomGenerator.RandFloat01() < inertiaSpeed.Length() / 4.0 + 0.05) //Линейная зависимость и > 5% шанс упасть.
		{
			SetUncon();
		}
		
		/*
		else if (inertiaSpeed[2] > 3.0)
		{
			if (m_randomGenerator.RandFloat01() < 0.75)
			{
				SetUncon();
			}			
		} else if (inertiaSpeed[2] > 2.0)
		{
			if (m_randomGenerator.RandFloat01() < 0.40)
			{
				SetUncon();
			}			
		} else if (inertiaSpeed[2] > 1.0)
		{
			if (m_randomGenerator.RandFloat01() < 0.10)
			{
				SetUncon();
			}			
		}
		*/
		
	};
	
	void SetUncon() {
		if (!m_characterControllerComponent.IsUnconscious()) 
		{					
			m_characterControllerComponent.SetUnconscious(true);			
			GetGame().GetCallqueue().CallLater(SetUnconOff, 2000, false);
		}
	};
	
	void SetUnconOff() {
		if (m_characterControllerComponent.IsUnconscious()) {
			m_characterControllerComponent.SetUnconscious(false);
			
		}
	}
	
}

