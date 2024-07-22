[ComponentEditorProps(category: "GameScripted/Misc", description: "")]
class Drg_NotepadRtComponentClass : ScriptComponentClass
{
}

class Drg_NotepadRtComponent : ScriptComponent
{
	[Attribute("")]
	ResourceName m_sPathLayout;
	Widget m_wRTRoot;
	
		
	//------------------------------------------------------------------------------------------------
	override void EOnInit(IEntity owner)
	{
		m_wRTRoot = GetGame().GetWorkspace().CreateWidgets(m_sPathLayout);
		RTTextureWidget rtTexture = RTTextureWidget.Cast(m_wRTRoot.FindAnyWidget("drg_Main_RTTexture"));
		rtTexture.SetGUIWidget(owner, 1);
	}

	//------------------------------------------------------------------------------------------------
	override void OnPostInit(IEntity owner)
	{
		SetEventMask(owner, EntityEvent.INIT);
	}

	//------------------------------------------------------------------------------------------------
	override void OnDelete(IEntity owner)
	{
		if (m_wRTRoot)
			m_wRTRoot.RemoveFromHierarchy();
	}	
}
