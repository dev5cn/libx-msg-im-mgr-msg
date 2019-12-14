/*
  Copyright 2019 www.dev5.cn, Inc. dev5@qq.com
 
  This file is part of X-MSG-IM.
 
  X-MSG-IM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  X-MSG-IM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU Affero General Public License
  along with X-MSG-IM.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "XmsgImMgrRawSysNeQuery.h"

XmsgImMgrRawSysNeQuery::XmsgImMgrRawSysNeQuery()
{

}

void XmsgImMgrRawSysNeQuery::handle(shared_ptr<XmsgNeUsr> nu, SptrClient client, SptrXitp trans, shared_ptr<XmsgImMgrRawSysNeQueryReq> req)
{
	shared_ptr<XmsgImMgrRawSysNeQueryRsp> rsp(new XmsgImMgrRawSysNeQueryRsp());
	for (int i = 0; i < XmsgImMgrCfg::instance()->cfgPb->h2n_size(); ++i)
	{
		auto& ne = XmsgImMgrCfg::instance()->cfgPb->h2n(i);
		XmsgMisc::insertKv(rsp->mutable_ne(), ne.cgt(), ne.neg());
	}
	trans->end(rsp);
}

XmsgImMgrRawSysNeQuery::~XmsgImMgrRawSysNeQuery()
{

}

