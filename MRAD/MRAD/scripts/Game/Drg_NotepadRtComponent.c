[ComponentEditorProps(category: "GameScripted/Misc", description: "")]
class Drg_NotepadRtComponentClass : ScriptComponentClass
{
}


class Drg_NotepadRtComponent : ScriptComponent
{
	[Attribute("")]
	ResourceName m_sPathLayout;
	Widget m_wRTRoot;
	
	[Attribute("", UIWidgets.EditBoxMultiline)]
	string m_sText;
	
	static ref map<ResourceName,RTTextureWidget> m_mStaticWidgets = new map<ResourceName,RTTextureWidget>();
	
		
	//------------------------------------------------------------------------------------------------
	override void EOnInit(IEntity owner)
	{
		ResourceName prefabName = owner.GetPrefabData().GetPrefabName();		
		RTTextureWidget rtTexture = m_mStaticWidgets.Get(prefabName);
		
		if (!rtTexture)
		{
			m_wRTRoot = GetGame().GetWorkspace().CreateWidgets(m_sPathLayout);
			rtTexture = RTTextureWidget.Cast(m_wRTRoot.FindAnyWidget("drg_Main_RTTexture"));
			RichTextWidget richRextureWidget = RichTextWidget.Cast(m_wRTRoot.FindAnyWidget("drg_Text"));
			richRextureWidget.SetText(m_sText);
			m_mStaticWidgets.Insert(prefabName, rtTexture);
		}
		
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
