//Andrew aka pyrolink - ajdecker1022@msn.com
//Manages the tech templates.  More detail: see CFormation and CEntityTemplate (collections)


#ifndef TECHNOLOGY_COLLECTION_INCLUDED
#define TECHNOLOGY_COLLECTION_INCLUDED

#include <vector>
#include "ps/CStr.h"
#include "ps/Singleton.h"
#include "Technology.h"
#include "ps/Game.h"

#define g_TechnologyCollection CTechnologyCollection::GetSingleton()

class CTechnologyCollection : public Singleton<CTechnologyCollection>
{
	typedef std::map<CStrW, CTechnology*> TechMap;
	typedef std::map<CStrW, CStr> TechFilenameMap;

	TechMap m_techs[PS_MAX_PLAYERS+1];
	TechFilenameMap m_techFilenames;
public:
	~CTechnologyCollection();
	CTechnology* getTechnology( CStrW techType, CPlayer* player );
	int loadTechnologies();
	void LoadFile( const char* path );
};

#endif
